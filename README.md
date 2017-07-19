# kuka_planning_interface
Action/Client Interface to test robot functionalities, such as executing CDS models + setting stiffness for teaching modes + simple motion generators in task and joint space.

| Dependencies  |
| ------------- |
| [kuka_interface_packages](https://github.com/nbfigueroa/kuka_interface_packages)    |
| [kuka-rviz-simulation](https://github.com/epfl-lasa/kuka-rviz-simulation)           |
| [state-transformers](https://github.com/epfl-lasa/state-transformers) |
| [CDS](https://github.com/epfl-lasa/coupled-dynamical-systems) |
|[task-planning](https://github.com/epfl-lasa/task-motion-planning-cds)|

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
