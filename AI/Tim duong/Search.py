# -*- coding: utf-8 -*-
"""
Created on Thu Oct  3 12:22:45 2024

@author: QTvnn
"""
import heapq
from haversine import haversine
import random


# Heuristic function: Dùng Haversine làm hàm heuristic
def heuristic(node1, node2):
    return haversine(node1, node2)

# A* algorithm implementation
def a_star_search(start_node, goal_node):
    open_list = []
    heapq.heappush(open_list, (0, start_node))  # (f_score, node)
    
    # Chuyển tọa độ từ list sang tuple để dùng làm key trong dictionary
    g_score = {tuple(start_node.root): 0}  # g_score giữ chi phí đi từ start đến node hiện tại
    parent = {tuple(start_node.root): None}  # parent dùng để lưu vết
    
    while open_list:
        _, current_node = heapq.heappop(open_list)
        
        # Nếu đã tới node đích
        if tuple(current_node.root) == tuple(goal_node.root):
            path = []
            total_distance = 0
            while current_node:
                path.append(current_node.root)
                if parent[tuple(current_node.root)] is not None:
                    # Tính khoảng cách từ node hiện tại tới node cha của nó
                    total_distance += current_node.get_distance(parent[tuple(current_node.root)].root)
                current_node = parent[tuple(current_node.root)]
            return path[::-1], total_distance  # Trả về đường đi và tổng khoảng cách
        
        # Duyệt các node con của current_node
        for neighbor in current_node.children_node:
            tentative_g_score = g_score[tuple(current_node.root)] + current_node.get_distance(neighbor.root)
            
            if tuple(neighbor.root) not in g_score or tentative_g_score < g_score[tuple(neighbor.root)]:
                parent[tuple(neighbor.root)] = current_node
                g_score[tuple(neighbor.root)] = tentative_g_score
                f_score = tentative_g_score + heuristic(tuple(neighbor.root), tuple(goal_node.root))
                heapq.heappush(open_list, (f_score, neighbor))
    
    return None, None  # Không tìm thấy đường đi
