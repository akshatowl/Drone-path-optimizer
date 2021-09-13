# Drone-path-optimizer


**A basic path optimizer for 3-points using ArduCopter and the GNC API by Intelligent Quads**  
**A working repository for testing basic path planning algorithms via Mavros messages**  
**Utilizes a basic segment to spline converter logic to have a smooth path traversing 3 waypoints**  

**The following was implemented on Gazebo-9 , ROS Melodic, Ardupilot(Master)**


![wp_initer](https://user-images.githubusercontent.com/58850654/133084315-95d7f1f7-9760-4178-8e1d-8225866d836a.gif)
```
git clone https://github.com/akshatowl/Drone-path-optimizer.git
```

You would need to get Mavros in the src/ folder of the repository, The following sets up mavros and mavlink inside the src folder

```
cd ~/Drone-path-optimizer/src  
rosinstall_generator --upstream mavros | tee /tmp/mavros.rosinstall  
rosinstall_generator mavlink | tee -a /tmp/mavros.rosinstall  
wstool merge -t src /tmp/mavros.rosinstall  
wstool update -t src  
rosdep install --from-paths src --ignore-src --rosdistro `echo $ROS_DISTRO` -y  

catkin build or catkin_make  
```


Make sure to source the workspace after building!  

```  
source devel/setup.bash  
```


To properly test the simulation, you would need 4 terminal windows. The mavros node has not been included in any launch file yet.    
Make sure to have the gazebo plugin for ardupilot on your system before this step!    

Terminal 1:   

```

gazebo --verbose ~/ardupilot_gazebo/worlds/iris_arducopter_runway.world  
```

Terminal 2: Start Ardupilot SITL  

```
cd ~/ardupilot/ArduCopter/
sim_vehicle.py -v ArduCopter -f gazebo-iris --console  
```  

Terminal 3: Initialise MavProxy from launch file  

```  

roslaunch drone_gazebo apm.launch  
```  

Terminal 4: Run the custom ROS Node (C++ here)  

```  
rosrun drone_gnc node_name  
```  

Go back to terminal 3 and set the sitl simulation to 'mode guided' 

Terminal 3 will display guided pretext if everything worked correctly.



Working demonstration:  



![wp_op](https://user-images.githubusercontent.com/58850654/133066547-b6e6cad2-b5d3-4d45-8490-7d623af8ac8f.gif)













