# -*- coding: utf-8 -*-
"""
Created on Sun Oct  6 09:27:29 2024

@author: QTvnn
"""




import tensorflow as tf; 
print(tf.config.list_physical_devices('GPU'))

from transformations import Compose, Resize, Normalize01, Re_Normalize01
import matplotlib.pyplot as plt
import os 
import numpy as np
import cv2

from simple_multi_unet_model import multi_unet_model, jacard_coef  


root_path = 'Carvana/'
IMG_HEIGHT = 64
IMG_WIDTH = 64
IMG_CHANNELS = 3 
n_classes = 2

X_test= []
y_test= []


for path, dirs, files in os.walk(root_path):
    if path == 'Carvana/Test\\Input':
        for file in files:
            X_test.append(cv2.imread(path + '/' + file))
        
    elif path == 'Carvana/Test\\Target':
        for file in files:
            y_test.append(cv2.imread(path + '/' + file))
        


from keras.models import load_model

def get_model():
    return multi_unet_model(n_classes=n_classes, IMG_HEIGHT=IMG_HEIGHT, IMG_WIDTH=IMG_WIDTH, IMG_CHANNELS=IMG_CHANNELS)

model = get_model()

model = load_model("models/model_unet_trained.keras",
                   custom_objects={'dice_loss_plus_2focal_loss': 'categorical_crossentropy',
                                   'jacard_coef':jacard_coef})




transforms = Compose([
        Resize(input_size=(IMG_HEIGHT, IMG_WIDTH, IMG_CHANNELS), target_size=(IMG_HEIGHT, IMG_WIDTH)),
        Normalize01()
    ])


for i in range(len(X_test)):
    X_test[i], y_test[i]  = transforms(X_test[i], y_test[i]) 



X_test = np.array(X_test)
y_test =  np.array(y_test)


import random
test_img_number = random.randint(0, len(X_test)-1)
test_img = X_test[test_img_number]
ground_truth=y_test[test_img_number]
test_img_input=np.expand_dims(test_img, 0)
prediction = (model.predict(test_img_input))
predicted_img=np.argmax(prediction, axis=3)[0,:,:]

import os 

img_path = 'Carvana/Input/0cdf5b5d0ce1_01.png'
img = cv2.imread(img_path)

img.shape

test_img = cv2.resize(test_img, (img.shape[1], img.shape[0]))

ground_truth = cv2.resize(ground_truth, (img.shape[1], img.shape[0]))

# predicted_img = cv2.resize(predicted_img, (img.shape[1], img.shape[0]))

transforms2 = Compose([
        Re_Normalize01()
    ])

test_img, ground_truth  = transforms2(test_img, ground_truth) 


plt.imshow(test_img)
plt.show()

plt.figure(figsize=(12, 8))
plt.subplot(231)
plt.title('Testing Image')
plt.imshow(test_img)
plt.subplot(232)
plt.title('Testing Label')
plt.imshow(ground_truth)
plt.subplot(233)
plt.title('Prediction on test image')
plt.imshow(predicted_img)
plt.show()


import os 

img_path = 'Carvana/Input/0cdf5b5d0ce1_01.png'
img = cv2.imread(img_path)

img.shape

plt.imshow(img)
plt.show()


transforms2 = Compose([
        Resize(input_size=(IMG_HEIGHT, IMG_WIDTH, IMG_CHANNELS), target_size=(IMG_HEIGHT, IMG_WIDTH)),
        Normalize01(),
        Resize(input_size=(1280, 1918, 3), target_size=(IMG_HEIGHT, IMG_WIDTH)),
        Re_Normalize01()
    ])

img, ground_truth  = transforms2(img, ground_truth) 


plt.imshow(img)
plt.show()


