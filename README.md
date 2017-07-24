# kuka_planning_interface
Action/Client Interface to test robot functionalities, such as executing CDS models + setting stiffness for teaching modes + simple motion generators in task and joint space.

## Dependencies

First, you need to install wstool:
```
$ sudo apt-get install python-wstool
```
From your catkin src directory, write the following lines:
```
$  wstool init
$  wstool merge kuka_planning_interface/dependencies.rosinstall 
$  wstool up
```
wstool gets all other git repository dependencies. After the steps above you should see extra catking packages in your src directory.
Finally, you need to install manually some additional packages as follows:
```
$ sudo apt-get install ros-indigo-pr2-mechanism-model ros-indigo-pr2-controller-manager ros-indigo-control-toolbox ros-indigo-pr2-mechanism-controllers
```

---
#### To test this interface in simulation
Launch rviz simulator 
```
$ roslaunch kuka_lwr_bringup lwr_simulation.launch
```
Cartesian-to-Joint/Joint-to-Cart Estimation
```
$ roslaunch state_transformers pouring_ctrls_sim.launch
```

#### To test this interface with the real robot
Launch rviz visualizer 
```
$ roslaunch kuka_lwr_bringup lwr_realtime.launch
```
Cartesian-to-Joint/Joint-to-Cart Estimation (not necessary for teaching commands)
```
$ roslaunch state_transformers pouring_ctrls_real.launch
```

---
#### Test Action Server/Client for KUKA control:

Launch server
```
$ roslaunch test_kuka server.launch
```

Launch client
```
$ roslaunch test_kuka client.launch
```

#### Actions available in test server:

CDS motions (velocity interface in bridge):
```
$ rosservice call /control_cmd_interface/kuka_action_cmd 'home'
$ rosservice call /control_cmd_interface/kuka_action_cmd 'pour'
$ rosservice call /control_cmd_interface/kuka_action_cmd 'back'
```

Teaching commands (velocity interface in bridge):
```
$ rosservice call /control_cmd_interface/kuka_action_cmd 'grav_comp'
$ rosservice call /control_cmd_interface/kuka_action_cmd 'safe_grav_comp'
$ rosservice call /control_cmd_interface/kuka_action_cmd 'joint_imp'
$ rosservice call /control_cmd_interface/kuka_action_cmd 'joint_stiff'
$ rosservice call /control_cmd_interface/kuka_action_cmd 'lock_joint_6'
$ rosservice call /control_cmd_interface/kuka_action_cmd 'lock_joint_7'
$ rosservice call /control_cmd_interface/kuka_action_cmd 'lock_joint_5_6'

```

Linear Joint Motion (position interface in bridge):
```
$ rosservice call /control_cmd_interface/kuka_action_cmd 'goto_init'
$ rosservice call /control_cmd_interface/kuka_action_cmd 'goto_home'
```
