<h1>ARNA SUMMER 2024 (ROS Kinetic)</h1>

**Skip to the bottom to read what is done, and what needs to be done.**



<h2>1. Simulation_ws</h2>
     Simulation_ws is where all the main things are for the simulated hospital world. 

<h3>a. To launch the hospital world with arna inside:</h3>

     source simulation_ws/devel/setup.bash
     
     roslaunch aws_robomaker_hospital_world view_hospital.launch 
     
<h3>b. To control ARNA using telop keyboard</h3>

**Run the code below in a separate terminal**

     rosrun teleop_twist_keyboard teleop_twist_keyboard.py cmd_vel:=/arna_base/arna_base_controller/cmd_vel

<h3>c. To launch Gmapping (mapping the hospital world using ARNA)</h3>

**Launch part (a)**

**Run the code below in a separate terminal**

     roslaunch aws_robomaker_hospital_world gmapping.launch

**Run the code below in a separate terminal**

     rosrun rviz rviz

**Run the code below in a separate terminal (if you want to move ARNA Around)**

     rosrun teleop_twist_keyboard teleop_twist_keyboard.py cmd_vel:=/arna_base/arna_base_controller/cmd_vel

**WARNING! The laser data and ARNA's orientation may not match in RViz. To "fix" this, go to user/arna_base/src/gazebo_ros_demos/arna_base_control/config/arna_base_control.yaml**

**Change the left wheels and right wheels from lines 13 - 16 if necessary**

<h3>d. To launch Navigations (for localization, path planning, and moving ARNA)</h3>

**Launch part (a)**

**Run the code below in a separate terminal**

     roslaunch aws_robomaker_hospital_world navigation_demo.launch
     
**Run the code below in a separate terminal**

     rosrun rviz rviz

**WARNING! The laser data and ARNA's orientation may not match in RViz. To "fix" this, go to user/arna_base/src/gazebo_ros_demos/arna_base_control/config/arna_base_control.yaml**

**Change the left wheels and right wheels from lines 13 - 16 if necessary**

**PLEASE FIX: ARNA Oscillates left and right after a goal is set (instead of completing the goal)**

_______________________________________________________________________________________
_______________________________________________________________________________________

<h2>2. ARNA Base with Kinova Gen3 7dof Arm</h2>

<h3>a. Arna Base</h3>

**File Location: user/arna_base/src/gazebo_ros_demos/arna_base_description/urdf/arna_base.xacro**

**Comment out the Arm (lines 6 - 10) and its joint (lines 17 - 25) if it interferes with the hokuyo lidar.** 

<h3>b. Kinova Arm</h3>

**File Location: user/arna_base/src/ros_kortex/kortex_gazebo/launch/spawn_kortex_robot.launch**

**The launch file might be edited**

**You can delete the ros_kortex package and install a new one from github (make sure to set the version to kinetic)**

**Make sure you source the arna_base project if you want to launch it**

roslaunch kortex_gazebo spawn_kortex_robot.launch

**If you have trouble running the newly installed arm**

**Go to ~/ros_kortex/kortex_gazebo/scripts/home_robot.py**

**Delete lines 7 and 8 (see below)**

from kortex_driver.msg import ActionNotification, ActionEvent
from kortex_driver.srv import ReadAction, ReadActionRequest, ExecuteAction, ExecuteActionRequest

**Try launching the files again and see if it works**
_______________________________________________________________________________________
_______________________________________________________________________________________

<h2>What is Done</h2>

**ARNA's Transformation in RViz is fixed, lidar should be facing the correct direction**

**A map of the hospital is created (SEE user/simulation_ws/src/aws-robomaker-hospital-world/maps/)**

**Create a new map of the hospital world if you want to using gmapping (make sure to load the map after you finished mapping)**

**Transformation and topics for ARNA localization and path planning are fixed**

**Kinova Gen3 7dof arm is attached to ARNA**

<h2>What Needs to be Done</h2>

**Fix the oscillation problem with ARNA's navigation when given a goal**

**SEE the problem above when you launch navigation_demo.launch**

**Establish control over the Kinova arm while it's on top of ARNA**

**Spawn Actors that move around in the hospital world**

**The spawning actors problem could be related to Gazebo being version 7 (too old)**

**Be able to control the Kinova arm and move ARNA around in the same RViz screen**

     


     
     
     
