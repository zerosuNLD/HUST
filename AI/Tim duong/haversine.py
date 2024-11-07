# -*- coding: utf-8 -*-
"""
Created on Thu Oct  3 13:25:07 2024

@author: QTvnn
"""
import math
import pickle

# Khoảng cách giữa 2 tọa độ
def haversine(coord1, coord2):
    # Chuyển đổi độ từ độ sang radian
    lat1, lon1 = math.radians(coord1[0]), math.radians(coord1[1])
    lat2, lon2 = math.radians(coord2[0]), math.radians(coord2[1])
    
    # Sự khác biệt giữa các tọa độ
    dlat = lat2 - lat1
    dlon = lon2 - lon1
    
    # Công thức Haversine
    a = math.sin(dlat / 2)**2 + math.cos(lat1) * math.cos(lat2) * math.sin(dlon / 2)**2
    c = 2 * math.asin(math.sqrt(a))
    
    # Bán kính trái đất (kilometers)
    r = 6371.0
    
    return c * r
