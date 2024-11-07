from transformations import Compose, Resize, Normalize01, DenseTarget, MoveAxis
import matplotlib.pyplot as plt
import os 
from sklearn.model_selection import train_test_split
import numpy as np
import random
import cv2

from SegmentationDataSet import Dataset
from torch.utils import data

'''
    Bước 1: Đọc dữ liệu và tiền xử lý dữ liệu 
'''

root_path = 'Carvana/'


inputs_dataset= []
targets_dataset = []
inputs_test_dataset= []
targets_test_dataset= []

for path, dirs, files in os.walk(root_path):
    if path == 'Carvana/Input':
        for file in files:
            inputs_dataset.append(cv2.imread(path + '/' + file))
        
    elif path == 'Carvana/Target':
        for file in files:
            targets_dataset.append(cv2.imread(path + '/' + file))
    
    elif path == 'Carvana/Test\\Input':
        for file in files:
            inputs_test_dataset.append(cv2.imread(path + '/' + file))
        
    elif path == 'Carvana/Test\\Target':
        for file in files:
            targets_test_dataset.append(cv2.imread(path + '/' + file))
        


#Tiền xử lý
IMG_HEIGHT = 64
IMG_WIDTH = 64
IMG_CHANNELS = 3 

transforms = Compose([
        DenseTarget(),
        Resize(input_size=(IMG_HEIGHT, IMG_WIDTH, IMG_CHANNELS), target_size=(IMG_HEIGHT, IMG_WIDTH)),
        Normalize01()
    ])

for i in range(len(inputs_dataset)):
    inputs_dataset[i], targets_dataset[i]  = transforms(inputs_dataset[i], targets_dataset[i]) 


inputs_dataset = np.array(inputs_dataset)
targets_dataset =  np.array(targets_dataset)



image_number = random.randint(0, len(inputs_dataset))


plt.figure(figsize=(12, 6))
plt.subplot(121)
plt.imshow(inputs_dataset[image_number])
plt.subplot(122)
plt.imshow(targets_dataset[image_number][:,:,0])
plt.show()


tar_dataset = targets_dataset[:,:,:,0]

n_classes = len(np.unique(targets_dataset))
from keras.utils import to_categorical
tar_dataset = to_categorical(tar_dataset, num_classes=n_classes)


#Chia cắt dữ liêụ thành tập huấn luyện và tập kiểm thử 
X_train, X_test, y_train, y_test = train_test_split(
    inputs_dataset, tar_dataset, test_size=0.2, random_state=42
)



'''
    Bước 2: Huấn luyện model
'''

n_classes = 2
IMG_HEIGHT = 64
IMG_WIDTH = 64
IMG_CHANNELS = 3 

from simple_multi_unet_model import multi_unet_model, jacard_coef  

metrics=['accuracy', jacard_coef]

# Tạo mô hình Unet để phân đoạn hình ảnh 
def get_model():
    return multi_unet_model(n_classes=n_classes, IMG_HEIGHT=IMG_HEIGHT, IMG_WIDTH=IMG_WIDTH, IMG_CHANNELS=IMG_CHANNELS)

model = get_model()
#Định nghĩa optimizer, loss function
model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=metrics)
model.summary()


history1 = model.fit(X_train, y_train, 
                    verbose=1, 
                    batch_size=32,
                    shuffle=True,
                    epochs=100, 
                    validation_data=(X_test, y_test))

from tensorflow.keras.models import save_model

save_model(model, 'models/model_unet_trained.keras')



history = history1
loss = history.history['loss']
val_loss = history.history['val_loss']
epochs = range(1, len(loss) + 1)
plt.plot(epochs, loss, 'y', label='Training loss')
plt.plot(epochs, val_loss, 'r', label='Validation loss')
plt.title('Training and validation loss')
plt.xlabel('Epochs')
plt.ylabel('Loss')
plt.legend()
plt.show()

acc = history.history['jacard_coef']
val_acc = history.history['val_jacard_coef']

plt.plot(epochs, acc, 'y', label='Training IoU')
plt.plot(epochs, val_acc, 'r', label='Validation IoU')
plt.title('Training and validation IoU')
plt.xlabel('Epochs')
plt.ylabel('IoU')
plt.legend()
plt.show()
