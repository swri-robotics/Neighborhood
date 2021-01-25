Neighborhood Environment
========================

This is a modified version of Microsoft's AirSim Neighboorhood environment
that is designed to be used with Unreal Engine 4.24, Airsim 1.3.1, and
ROS Melodic on Ubuntu 18.04.

More documentation will be coming soon.  Very brief setup instructions:

Prerequisites
-------------

You should be running [Ubuntu Linux 18.04](https://releases.ubuntu.com/18.04.4/)
with [ROS Melodic](http://wiki.ros.org/melodic/Installation/Ubuntu).

Next, install some packages we'll use:

```bash
sudo apt update
sudo apt install build-essential git git-lfs gcc-8 g++-8 python-catkin-tools
```

Building the Environment
------------------------

1. Install [Unreal Engine 4.24](https://www.unrealengine.com/); you'll need to
   register for an account, then clone and build the `4.24` tag.
   Also install [ue4cli](https://github.com/adamrehn/ue4cli)
   to provide a nice command line interface for it.

2. Clone SwRI's AirSim fork:
   ```bash
   mkdir -p $HOME/src/
   cd $HOME/src
   git clone https://github.com/swri-robotics/AirSim.git
   ```

3. Clone this repository inside AirSim's Unreal/Environments directory:
   ```bash
   mkdir -p $HOME/src/AirSim/Unreal/Environments/
   cd $HOME/src/AirSim/Unreal/Environments/
   git clone https://github.com/swri-robotics/Neighborhood.git
   ```

4. Use git-lfs to grab the full contents of the directory:
```bash
cd $HOME/src/AirSim/Unreal/Environments/Neighborhood
git lfs pull
```

5. Build AirSim:
   ```bash
   cd $HOME/src/AirSim
   ./setup.sh
   ./build-neighborhood.sh
   ```

6. Build the Neighborhood environment:
   ```bash
   cd $HOME/src/AirSim/Unreal/Environments/Neighborhood
   ue4 build
   ```

Building the ROS Node
---------------------

1. Create a catkin workspace:
   ```bash
   cd $HOME/src/AirSim/ros
   . /opt/ros/melodic/setup.bash
   rosdep install src -y --from-paths -i
   catkin init
   catkin config -e /opt/ros/melodic
   catkin config --install
   catkin config --cmake-args -DCMAKE_BUILD_TYPE=RelWithDebInfo
   ```

2. Build it; note that it requires GCC 8:
   ```bash
   CC=gcc-8 CXX=g++-8 catkin build
   ```

Configuring Airsim
------------------

1. Copy the `settings.json` file in this repository into this appropriate location:
   ```bash
   mkdir $HOME/Documents/AirSim/
   cp settings.json $HOME/Documents/AirSim/
   ```

2. The default settings are a reasonable approximation of sensors available on a
   real vehicle, but you may have performance issues.  Consult
   [settings.md](https://microsoft.github.io/AirSim/settings/) for documentation on available parameters.
   In particular, reducing the number of camera and the cameras' resolutions
   will significantly improve performance.

Running the Simulation
----------------------

1. Open a terminal and run the Neighborhood environment:
   ```bash
   cd $HOME/src/AirSim/Unreal/Environments/Neighborhood
   ue4 run -opengl4
   ```

2. The startup dialog will warn you that OpenGL is deprecated.  That's
   ok, just click through it.

3. After the editor is open, click the "Run" button at the top to start
   the simulation.

4. Open another terminal and run the ROS node:
   ```bash
   . $HOME/src/AirSim/ros/install/setup.bash
   roslaunch airsim_car_ros_pkgs airsim_node.launch
   ```

4. If it connects to AirSim, you will see output like this:
   ```bash
   started roslaunch server http://tachikoma:34535/
   
   SUMMARY
   ========
   
   PARAMETERS
    * /airsim_node/imu_calibration: 0.93
    * /airsim_node/is_vulkan: False
    * /airsim_node/speed_calibration: 0.85
    * /airsim_node/update_airsim_control_every_n_sec: 0.02
    * /airsim_node/update_airsim_img_response_every_n_sec: 0.05
    * /airsim_node/update_lidar_every_n_sec: 0.05
    * /rosdistro: melodic
    * /rosversion: 1.14.5
   
   NODES
     /
       airsim_node (airsim_car_ros_pkgs/airsim_car_node)
   
   auto-starting new master
   process[master]: started with pid [19953]
   ROS_MASTER_URI=http://localhost:11311
   
   setting /run_id to 2c394b2e-9bc1-11ea-bfff-00e04c680218
   process[rosout-1]: started with pid [19965]
   started core service [/rosout]
   process[airsim_node-2]: started with pid [19969]
   [ INFO] [1590106457.170917132]: Initializing swri_profiler...
   simmode_name: Car
   [ INFO] [1590106457.181546505]: Read dynamic parameter imu_calibration = 0.930000
   [ INFO] [1590106457.185337524]: Read dynamic parameter speed_calibration = 0.850000
   [ INFO] [1590106457.208716734]: Found car: PhysXCar
   [ INFO] [1590106457.277512307]: Sensor Init
   [ INFO] [1590106457.277549482]: Sensor: Name( Imu )
   [ INFO] [1590106457.277593210]: Sensor: Type ( IMU )
   [ INFO] [1590106457.277967857]: Sensor: Name( VLP16_1 )
   [ INFO] [1590106457.278011484]: Sensor: Type ( Lidar )
   [ INFO] [1590106457.278399314]: Sensor: Name( VLP16_2 )
   [ INFO] [1590106457.278436145]: Sensor: Type ( Lidar )
   [ INFO] [1590106457.278892115]: Sensor: Name( VLP16_3 )
   [ INFO] [1590106457.278939072]: Sensor: Type ( Lidar )
   Waiting for connection -
   Connected!
   
   Client Ver:1 (Min Req:1), Server Ver:1 (Min Req:1)
   Waiting for connection -
   Connected!
   
   Client Ver:1 (Min Req:1), Server Ver:1 (Min Req:1)
   Waiting for connection -
   Connected!
   
   Client Ver:1 (Min Req:1), Server Ver:1 (Min Req:1)
   [ INFO] [1590106457.283268855]: AirsimROSWrapper Initialized!
   [ WARN] [1590106457.304383313]: PhysXCar Command Received!!! Throttle cmd = 0.000000
   ```

   You can push Ctrl+C at any time to shut it down.

5. While the node is running, you can open another terminal and use ROS 
   commands or run other nodes to interact with it.

   ```bash
   . $HOME/src/AirSim/ros/install/setup.bash
   rostopic list
   ...
   ```

