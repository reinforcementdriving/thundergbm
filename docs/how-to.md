ThunderGBM How To
======
This page is for key instructions of intalling, using and contributing to ThunderGBM. Everyone in the community can contribute to ThunderGBM to make it better.

## How to install ThunderGBM
First of all, you need to install the prerequisite libraries and tools. Then you can download and install ThunderGBM. 
### Prerequisites
* cmake 2.8 or above | [C++ boost](https://www.boost.org/) 
    * gcc 4.8 or above for Linux | [CUDA](https://developer.nvidia.com/cuda-downloads) 8 or above
    * Visual C++ for Windows | CUDA 10


### Download
```bash
git clone https://github.com/zeyiwen/thundergbm.git
cd thundergbm
#under the directory of thundergbm
git submodule init cub && git submodule update
```
### Build on Linux 
```bash
cd thundergbm
mkdir build && cd build && cmake .. && make -j
```

### Quick Start
```bash
./bin/thundergbm-train ../dataset/machine.conf
./bin/thundergbm-predict ../dataset/machine.conf
```
You will see `RMSE = 0.489562` after successful running.

### Build on Windows
Use the following commands to build the boost library under the Boost directory:
```bash
.\bootstrap.bat
.\b2 --toolset=[msvc version] --build-type=complete --prefix="C:\boost" install
```
[msvc version] is the version of compiler in the Visual Studio (e.g., msvc-14.1). You can specify other paths you like to replace "C:\boost".

Then, you can build the ThunderGBM library as follows:
```bash
cd thundergbm
mkdir build
cd build
cmake .. -DBOOST_ROOT=[path_to_boost] -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE -DBUILD_SHARED_LIBS=TRUE -G "Visual Studio 15 2017 Win64"
```
[path_to_boost] is the installation prefix of Boost (e.g., C:\boost). You need to change the Visual Studio version if you are using a different version of Visual Studio. Visual Studio can be downloaded from [this link](https://www.visualstudio.com/vs/). The above commands generate some Visual Studio project files, open the Visual Studio project to build ThunderGBM. Please note that CMake should be 3.4 or above for Windows. Furthermore, you should add the path of the boost library directory (e.g., C:\boost\lib) to the system variable "Path".

## How to build test for ThunderGBM
For building test cases, you also need to obtain ``googletest`` using the following command.
```bash
#under the thundergbm directory
git submodule update --init src/test/googletest
```
After obtaining the ``googletest`` submodule, you can build the test cases by the following commands.
```bash
cd thundergbm
mkdir build && cd build && cmake -DBUILD_TETS=ON .. && make -j
```

## How to use ThunderGBM for ranking

There are two key steps to use ThunderGBM for ranking.
* First, you need to choose ``rank:pairwise`` or ``rank:ndcg`` to set the ``objective`` of ThunderGBM.
* Second, you need to have a file called ``[train_file_name].group`` to specify the number of instances in each query.

The remaining part is the same as classification and regression. Please refer to [Parameters](parameters.md) for more information about setting the parameters.
