# H7ThreadX
Minimal C++ framework based on ThreadX RTOS mainly for learning, exploration and demonstration of tooling and modern C++ on embedded devices. 

This is based on an exported CubeMX project file for a STM32 H743XI-E02 which has been split it into separate parts that can be managed and possibly moved to sub-repositories (also to represent different boards and configurations).
In the current state Visual Studio can be used to upload and debug the resulting demo-App. 

## Features
* CMake based build pipeline
* Integration of tools for flashing, updating and debugging
* C++ abstraction of ThreadX threading and OS primitives
* Split into multiple libraries for re-use of targets in other projects
* Minimal demo

## Planned high-level features
* Support for Visual Studio Code
* Support for multiple boards
* C++ unit testing with mocking support (currently a pipedream)
* Abstraction of board configuration (generator from cubemx project file)
  

## Structure
* AZURE_OS - A minimal demo project
* foundation - C++ abstraction and tools for ThreadX and generic embedded facilities
  
## Building
```
cmake --preset Release
cmake --build --preset Release
```
The resulting .bin file can be uploaded to an evaluation kit using the USB mounted target, but you can can also use Visual Studio to integrate uploading and debugging. 
In order to get this working, the **launch** folder contains the scripts for VS and VS-code. Copying the into you .vs/.vscode directory below the project directory should work. 

### Upload
In Visual Studio: Select the lauch target and start debugging/running

### Prerequistes
This should be building out of the box as long a compatible arm-none-eabi-gcc is installed. Currently 11.3 and above should do the trick.
As the project is based on the  [STMCubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) and [STMCubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) respectively, installing them will make all tools used by the project available (compiler, uploader, ...).



