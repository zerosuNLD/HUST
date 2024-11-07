import pickle
from Search import a_star_search
import random
from draw_in_map import Map



# Đọc dữ liệu từ file (deserialization)
with open('graph_nodes.pkl', 'rb') as file:
    nodes = pickle.load(file)

# Hiển thị thông tin của các nodes đã load
# for node in nodes:
#     node.display()

CENTER_LOCATION = [21.0285, 105.8542]

m = Map(center_location=CENTER_LOCATION,
        nodes=nodes)

# Tìm đường
idx = random.randint(0, len(nodes) - 1)

path, total_distance = a_star_search(nodes[0], nodes[idx])
print("Khoang cach = ", total_distance, "kilomet")



# m.draw_point_to_map(point=CENTER_LOCATION) # Vẽ điểm trung tâm trên map

m.draw_circle_around_center_location() # Vẽ vòng tròn quanh điểm trung tâm

# m.draw_nodes_on_the_graph() # Vẽ các node trên đồ thị 

# m.draw_path_vector_on_the_graph() #Vẽ các con đường có hướng trên đồ thị

m.draw_point_to_map(point=nodes[0].root, 
                    popup="Điểm xuất phát",
                    color='blue') # Vẽ điểm xuất phát trên đồ thị

m.draw_point_to_map(point=nodes[idx].root,
                    popup="Điểm đến",
                    color='red') # Vẽ điểm đến trên đồ thị

m.draw_path_point_and_point(path=path) # Vẽ đường đi được tìm thấy giữa 2 điểm 

m.add_note_box(total_distance)

# Lưu bản đồ thành file HTML
m.save("map_with_click.html")
