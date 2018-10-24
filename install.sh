#!/bin/sh

cd ~
mkdir beholder

#TensorFlow(Bazel)
sudo apt-get install openjdk-8-jdk -y
echo "deb [arch=amd64] http://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
curl https://bazel.build/bazel-release.pub.gpg | sudo apt-key add -
sudo apt-get update && sudo apt-get install bazel -y

#TensorFlow(Protobuf)
sudo apt-get install autoconf automake libtool curl make g++ unzip -y
cd ~/beholder
git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git submodule update --init --recursive
./autogen.sh
./configure
make && sudo make install
sudo ldconfig

#TensorFlow(Eigen)
cd ~/beholder
wget https://github.com/eigenteam/eigen-git-mirror/archive/3.3.5.zip
unzip 3.3.5.zip
rm 3.3.5.zip
cd eigen-git-mirror-3.3.5
mkdir build && cd build
cmake ..
make
sudo make install

#TensorFlow
sudo apt-get install python3-numpy python3-dev python3-pip python3-wheel
sudo pip3 install six numpy wheel

#OpenCV
sudo apt-get install build-essential checkinstall cmake pkg-config yasm -y
sudo apt-get install git gfortran -y
sudo apt-get install libjpeg8-dev libjasper-dev libpng12-dev -y
sudo apt-get install libtiff5-dev -y
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev -y
sudo apt-get install libxine2-dev libv4l-dev -y
sudo apt-get install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev -y
sudo apt-get install qt5-default libgtk2.0-dev libtbb-dev -y
sudo apt-get install libatlas-base-dev -y
sudo apt-get install libfaac-dev libmp3lame-dev libtheora-dev -y
sudo apt-get install libvorbis-dev libxvidcore-dev -y
sudo apt-get install libopencore-amrnb-dev libopencore-amrwb-dev -y
sudo apt-get install x264 v4l-utils -y
sudo apt-get install python-dev python-pip python3-dev python3-pip -y
sudo pip3 install numpy scipy matplotlib scikit-image scikit-learn ipython -y
cd ~/beholder
git clone https://github.com/opencv/opencv.git
cd opencv && git checkout 3.4.1
cd ~/beholder
git clone https://github.com/opencv/opencv_contrib.git
cd opencv_contrib && git checkout 3.4.1
cd ~/beholder/opencv && mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D INSTALL_C_EXAMPLES=ON \
      -D INSTALL_PYTHON_EXAMPLES=ON \
      -D WITH_TBB=ON \
      -D WITH_V4L=ON \
      -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules \
      -D BUILD_EXAMPLES=ON ..
nproc
# substitute 4 by output of nproc
make -j4
sudo make install
sudo sh -c 'echo "/usr/local/lib" >> /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig

#Flir SDK

#wiring pi
cd ~/beholder
git clone git://git.drogon.net/wiringPi
cd wiringPi
git pull origin
./build
