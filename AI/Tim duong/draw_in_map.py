# -*- coding: utf-8 -*-
"""
Created on Thu Oct  3 13:45:17 2024

@author: QTvnn
"""

# node_start la node bat dau
# node_end la node ket thuc
# m la map truyen vao

import folium
from folium.plugins import PolyLineTextPath


class Map:
    def __init__(self, center_location=None, nodes=None):
        # Cac nodes duong truyền vào ở dạng Graph không phải tọa độ
        self.center_location = center_location
        self.nodes = nodes
        self.m = folium.Map(location= self.center_location,zoom_start=15)
    
    def setCenterLocation(self, center_location):
        self.center_location = center_location
        self.m = folium.Map(location= self.center_location,zoom_start=15)


    def getCenterLocation(self):
        return self.center_location

    def draw_point_to_map(self,
                          point=None, 
                          popup=None, # Ghi chú
                          color='blue'):
        folium.Marker(
            location=point,
            popup=popup,    
            icon=folium.Icon(color=color)  # Thay đổi màu sắc tại đây
        ).add_to(self.m)

    def draw_circle_around_center_location(self,
                    radius=500,
                    color='blue',
                    fill=True,
                    fill_color='blue'):
        folium.Circle(
            location=self.center_location,
            radius=500,  # Bán kính tính bằng mét
            color='blue',
            fill=True,
            fill_color='blue'
        ).add_to(self.m)
    

    # Hàm vẽ đường (vector) giữa 2 node
    def draw_line_vector(self, 
                         node_start=None, 
                         node_end=None, 
                         color='red', 
                         weight=4, 
                         opacity=0.7, 
                         text='   ▶', 
                         repeat=False, offset=1, 
                         attributes={'fill': 'blue', 'font-weight': 'bold'}):
        
        # Vẽ đường giữa hai tọa độ node_start và node_end
        polyline = folium.PolyLine(
            locations=[node_start, node_end],  # Tọa độ của 2 node
            color=color,  # Màu vector
            weight=weight,  # Độ dày vector
            opacity=opacity  # Độ trong suốt vector
        ).add_to(self.m)  # Thêm vào bản đồ
        
        # Thêm mũi tên vào đường để chỉ hướng
        arrow = PolyLineTextPath(
            polyline,  # Đối tượng đường thẳng
            text=text,  # Ký tự hiển thị (ví dụ: mũi tên)
            repeat=repeat,  # Có lặp lại mũi tên hay không
            offset=offset,  # Độ lệch (vị trí mũi tên trên đường)
            attributes=attributes  # Thuộc tính của text (màu, font-weight)
        )
    
        # Thêm mũi tên vào bản đồ
        self.m.add_child(arrow)
    
        

    # Vẽ đường thẳng giữa 2 node trên bản đồ.
    def draw_line(self,
                  node_start,
                  node_end, 
                  color='red',
                  weight=4,
                  opacity=0.7):
        
        folium.PolyLine(
            locations=[node_start, node_end],  # Tọa độ của 2 node
            color=color,  # Màu của vector
            weight=weight,  # Độ dày của vector
            opacity=opacity  # Độ trong suốt của vector
        ).add_to(self.m)
    
        
        
    # Vẽ chấm tròn tại một vị trí cụ thể trên bản đồ.
    def draw_circle_marker(self,
                           location=None,
                           radius=4,
                           color='blue',
                           fill=True,
                           fill_color='blue',
                           fill_opacity=0.9,
                           popup=None):
        
        folium.CircleMarker(
            location=location,
            radius=radius,
            color=color,
            fill=fill,
            fill_color=fill_color,
            fill_opacity=fill_opacity,
            popup=popup
        ).add_to(self.m)
        
        
    # Vẽ các node có trên đồ thị 
    def draw_nodes_on_the_graph(self):
        for node in self.nodes:
            self.draw_circle_marker(location=node.root)
    
    
    # Vẽ đường đi không có hướng trên đồ thị
    def draw_path_on_the_graph(self):
        for node in self.nodes:
            for child in node.children_node:
                self.draw_line(node_start=node.root, 
                                      node_end=child.root)
                
                
                
    # Vẽ đường đi có hướng trên đồ thị
    def draw_path_vector_on_the_graph(self):
        for node in self.nodes:
            for child in node.children_node:
                self.draw_line_vector(node_start=node.root, 
                                      node_end=child.root)
    
    # Vẽ đường đi giữa 2 điểm trên đồ thị
    def draw_path_point_and_point(self, 
                                path=None):
        for idx in range(len(path)-1):
            self.draw_line_vector(node_start=path[idx], 
                                  node_end=path[idx+1])
    
    def add_note_box(self, total_distance=None):
        note_html = f"""
        <div style="position: fixed; 
                    bottom: 50px; 
                    left: 50px; 
                    width: 300px; 
                    height: 100px; 
                    border-radius: 20px;
                    background-color: lightblue; 
                    border: 2px solid black; 
                    z-index: 9999; 
                    padding: 10px;
                    box-shadow: 2px 2px 10px rgba(0, 0, 0, 0.5);
                    font-size: 16px;">
            <h4 style="margin: 0;">Thông tin tổng khoảng cách</h4>
            <p style="margin: 5px 0;">Tổng khoảng cách: <strong>{total_distance:.2f} km</strong></p>
        </div>
        """
        self.m.get_root().html.add_child(folium.Element(note_html))
        
        
    def save(self, link=None):
        self.m.save("map_with_click.html")
