<h1>**ARNA SUMMER 2024**</h1>



<h2>**1. Simulation_ws**</h2>
     Simulation_ws is where all the main things are for the simulated hospital world. 
     **To launch the hospital world with arna inside:**
     <py>source simulation_ws/devel/setup.bash
     roslaunch aws_robomaker_hospital_world view_hospital.launch </py>
     **To control ARNA using telop keyboard**
     **Run the code below in a separate terminal**
     rosrun teleop_twist_keyboard teleop_twist_keyboard.py cmd_vel:=/arna_base/arna_base_controller/cmd_vel
     
     
     
