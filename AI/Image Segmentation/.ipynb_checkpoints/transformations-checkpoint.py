'''
Tiền xử lý
'''
import numpy as np
from skimage.transform import resize
import queue


def bytescale(data, cmin=None, cmax=None, high=255, low=0):
    """ 
    
    """
    if data.dtype == np.uint8:
        return data

    if cmin is None:
        cmin = data.min()
    if cmax is None:
        cmax = data.max()

    # Convert data to float and normalize
    cmin = float(cmin)
    cmax = float(cmax)

    scale = (high - low) / (cmax - cmin)
    bytedata = (data - cmin) * scale + low
    return np.clip(bytedata, low, high).astype(np.uint8)


def create_dense_target(tar: np.ndarray):
    '''
    Nhiệm vụ chuyển đổi một mảng nhãn đầu vào (dữ liệu phân đoạn ảnh hoặc nhãn lớp) 
    thành một mảng nhãn mới, nơi các giá trị nhãn được ánh xạ thành các số nguyên 
    liên tiếp bắt đầu từ 0.
    '''
    
    classes = np.unique(tar)    
    dummy = np.zeros_like(tar)
    for idx, value in enumerate(classes):
        mask = np.where(tar == value) #Tìm tất cả vị trí trong tar có giá trị bằng value 
        dummy[mask] = idx
        
    return dummy

def normalize_01(inp: np.ndarray):
    '''
    Chuẩn hóa hình ảnh về dạng 0 -> 1
    '''
    inp_out = (inp - np.min(inp)) / np.ptp(inp)
    return inp_out

def normalize(inp: np.ndarray, 
              mean: float, 
              std: float):
    '''
    Chuẩn hóa z-score, đưa dữ liệu về phân phối có trung bình 0 
    và độ lệch chuẩn 1. Điều này giúp các mô hình học máy dễ dàng
    xử lý dữ liệu hơn, đặc biệt là trong các trường hợp mà giá trị
    của các tính năng (features) có thang đo khác nhau
    
    Ví dụ:
    inp = np.array[10, 20, 30, 40, 50] -> inp_out = [-2.0, -1.0, 0.0, 1.0, 2.0]
    '''
    inp_out = (inp - mean) / std
    return inp_out

def re_normalize(inp: np.ndarray,
                 low: int = 0,
                 high: int = 255
                 ):
    '''
    Chuyển từ dạng normalize (0-1 hoặc z-score) về dạng default: [0, 255]
    
    Parameters:
    - inp: Mảng numpy đầu vào, giá trị thường nằm trong khoảng [0, 1] hoặc đã được chuẩn hóa z-score.
    - low: Giá trị thấp nhất trong khoảng đầu ra (mặc định là 0).
    - high: Giá trị cao nhất trong khoảng đầu ra (mặc định là 255).
    
    Returns:
    - Mảng numpy với giá trị nằm trong khoảng [low, high], và kiểu dữ liệu là uint8.
    '''
    
    # Sử dụng hàm bytescale để chuyển đổi dữ liệu về khoảng [low, high]
    inp_out = bytescale(inp, low=low, high=high)
    
    return inp_out

class Compose:
    def __init__(self,transforms: queue):
        self.transforms = transforms
        
    def __call__(self, inp, target):
        for t in self.transforms:
            inp, target = t(inp, target)
        return inp, target


    def __repr__(self): 
        return str([transform for transform in self.transforms])
    

class MoveAxis:
    """From [H, W, C] to [C, H, W]"""

    def __init__(self, transform_input: bool = True, transform_target: bool = False):
        self.transform_input = transform_input
        self.transform_target = transform_target

    def __call__(self, inp: np.ndarray, tar: np.ndarray):
        if self.transform_input: inp = np.moveaxis(inp, -1, 0)
        if self.transform_target: tar = np.moveaxis(inp, -1, 0)

        return inp, tar

    def __repr__(self):
        return str({self.__class__.__name__: self.__dict__})
    
    
class DenseTarget:
    """Creates segmentation maps with consecutive integers, starting from 0"""

    def __init__(self):
        pass

    def __call__(self, inp: np.ndarray, tar: np.ndarray):
        tar = create_dense_target(tar)

        return inp, tar

    def __repr__(self):
        return str({self.__class__.__name__: self.__dict__})

class Resize:
    def __init__(self,
                 input_size: tuple,
                 target_size: tuple,
                 input_kwargs: dict = {},
                 target_kwargs: dict = {'order': 0, 'anti_aliasing': False, 'preserve_range': True}
                 ):
        self.input_size = input_size
        self.target_size = target_size
        self.input_kwargs = input_kwargs
        self.target_kwargs = target_kwargs

    def __call__(self, inp: np.ndarray, tar: np.ndarray):
        self.input_dtype = inp.dtype
        self.target_dtype = tar.dtype

        inp_out = resize(image=inp,
                         output_shape=self.input_size,
                         **self.input_kwargs
                         )
        tar_out = resize(image=tar,
                         output_shape=self.target_size,
                         **self.target_kwargs
                         ).astype(self.target_dtype)
        return inp_out, tar_out

    def __repr__(self):
        return str({self.__class__.__name__: self.__dict__})
    
class Normalize01:
    def __init__(self):
        pass
    
    def __call__(self, inp, tar):
        inp = normalize_01(inp)
        
        return inp, tar
    
    def __repr__(self):
       return str({self.__class__.__name__: self.__dict__})
    
class Normalize:
    """Normalize based on mean and standard deviation."""

    def __init__(self,
                 mean: float,
                 std: float,
                 transform_input=True,
                 transform_target=False
                 ):
        self.transform_input = transform_input
        self.transform_target = transform_target
        self.mean = mean
        self.std = std

    def __call__(self, inp, tar):
        inp = normalize(inp, mean=self.mean, std=self.std)

        return inp, tar

    def __repr__(self):
        return str({self.__class__.__name__: self.__dict__})
    

class Re_Normalize01:
    def __init__(self):
        pass
    
    def __call__(self, inp, tar):
        inp = re_normalize(inp)
        
        return inp, tar
    
    def __repr__(self):
       return str({self.__class__.__name__: self.__dict__})
   
    
    
class AlbuSeg2d:
    def __init__(self, albu):
        self.albu = albu

    def __call__(self, inp, tar):
        # input, target
        out_dict = self.albu(image=inp, mask=tar)
        input_out = out_dict['image']
        target_out = out_dict['mask']

        return input_out, target_out

    def __repr__(self):
        return str({self.__class__.__name__: self.__dict__})
    
    
    
    
    
    