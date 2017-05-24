Instruções para utilizar o exemplo:

>> criar pacote ROS (ex: serial_communication_example):
1) $ cd ~/catkin_ws/src
2) $ catkin_create_pkg serial_communication_example std_msgs rospy roscpp serial_communication_channels

>> copiar os seguintes ficheiros (da pasta "pc_node_code") para o pacote ROS (serial_communication_example/src):
	- pc_node_example.cpp
	- serial_communication_example.c
	- serial_communication_example.h

>> na CMakeLists.txt do pacote ROS, adicionar, no final:

add_executable(communications_example src/pc_node_example.cpp src/serial_communications_example.c)
target_link_libraries(communications_example ${catkin_LIBRARIES} usb-1.0 -lserial)
add_dependencies(communications_example decision_node_generate_messages_cpp)

3) $ cd ~/catkin_ws
4) $ catkin_make
