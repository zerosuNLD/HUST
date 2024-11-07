import torch
from skimage.io import imread

class Dataset:
    def __init__(self,
                 inputs: list,
                 targets: list,
                 transforms=None
                 ):
        self.inputs = inputs
        self.targets = targets
        self.transforms = transforms
        self.inputs_dtype = torch.float32
        self.targets_dtype = torch.long
    

    def loadData(self):
        inputs_dataset = []
        targets_dataset = []
        for input_ID, target_ID in zip(self.inputs, self.targets):
            
            inp, tar =  imread(input_ID), imread(target_ID)
            
            # Tiền xử lý nếu có
            if self.transforms is not None:
                inp, tar = self.transforms(inp, tar)
        
             # Chuyển thành dạng tensor
            inp, tar = torch.from_numpy(inp).type(self.inputs_dtype), torch.from_numpy(tar).type(self.targets_dtype)
        
            inputs_dataset.append(inp)
            targets_dataset.append(tar)
        
           
        return  inputs_dataset, targets_dataset
        