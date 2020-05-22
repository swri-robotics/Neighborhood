Neighborhood Environment
========================

This is a modified version of Microsoft's AirSim Neighboorhood environment
that is designed to be used with Unreal Engine 4.24, Airsim 1.3.1, and
ROS Melodic on Ubuntu 18.04.

More documentation will be coming soon.  Very brief setup instructions:

Building the Environment
------------------------

1. Install [Unreal Engine 4.24](https://www.unrealengine.com/); you'll need to
   register for an account, then clone and build the `4.24` tag.
   Also install [ue4cli](https://github.com/adamrehn/ue4cli)
   to provide a nice command line interface for it.

2. Install some prerequisites:
   ```bash
   sudo apt update && sudo apt install build-essential git git-lfs gcc-8 g++-8
   ```

3. Clone SwRI's AirSim fork:
   ```bash
   mkdir -p $HOME/src/
   cd $HOME/src
   git clone https://github.com/swri-robotics/AirSim.git
   ```

4. Clone this repository inside AirSim's Unreal/Environments directory:
   ```bash
   mkdir -p $HOME/src/AirSim/Unreal/Environments/
   cd $HOME/src/AirSim/Unreal/Environments/
   git clone https://github.com/swri-robotics/Neighborhood.git
   ```

5. Build AirSim:
   ```bash
   cd $HOME/src/AirSim
   ./setup.sh
   ./build-neighborhood.sh
   ```

6. Run the Neighborhood environment:
   ```bash
   cd $HOME/src/AirSim/Unreal/Environments/Neighborhood
   ue4 build
   ue4 run -opengl4
   ```

Building the ROS Nodes
----------------------

The ROS node is designed to run on [Ubuntu Linux 18.04](https://releases.ubuntu.com/18.04.4/)
with [ROS Melodic](http://wiki.ros.org/melodic/Installation/Ubuntu).  Ensure
you have them installed first.

Stay tuned for instructions on building & running the ROS node.
