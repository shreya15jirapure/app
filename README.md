# HPC and GDCU Communication System p

This project implements communication between a High-Performance Computing (HPC) server and a General Data Collection Unit (GDCU) client. The server listens for connections from the GDCU client and handles signals related to Single Pedal Drive (SPD). The GDCU client sends SPD-related signals to the HPC server and receives responses.

## Project Structure

├── build/ 
|         └── bin/
|                ├── HPC_SERVER_APP # HPC Server binary 
|                └── GDCU_CLIENT_APP # GDCU Client binary 
├── GDCU/ 
|       ├── gdcu.cpp  # server client comm logic for GDCU
│       ├── main.cpp # GDCU APP entry point
├── HPC/ 
|      ├── App_HPC_Get_Set.c  # hpc single step signal handle logic 
|      ├── HPC_SinglePedalDrive.c  # hpc single step functional logic
│      ├── server.c # HPC Server code
│      └── main.c # HPC app entry point
├── CMakeLists.txt # Build configuration
└── README.md # Project documentation

## Prerequisites

1. **Linux-based system** (tested on Ubuntu 22.04.5).
2. **CMake** installed (to build the project)  (version 3.22.1).
3. **GCC** or any other compatible C/C++ compiler installed   (version 11.4.0).

## Build Steps for Compilation on Linux

from project root dir

1. mkdir build
2. cd build
3. cmake ..
4. make

## Build Steps for CROSS Compilation on ARM

from project root dir

1. mkdir build
2. cd build
3. cmake .. -DCMAKE_TOOLCHAIN_FILE=/toolchain-s32g3.cmake
4. make

## RUN STEPS

cd build
./bin/HPC_SERVER    will start HPC server
./bin/GDCU_SERVER   will start the GDCU server

## Automated Scripts

from project root directory  /FINAL_APP

./build_and_sync.sh        -> will compile and genrate binary for the projects
                              customised to generate bin for both stripped and unstripped version
                              customised to select buid for local compialtion and cross compilation

                            Genrated Files For Local build:
                            /build/bin/
                                     /stripped/HPC_CLIENT_APP
                                     /unstripped/GDCU_SERVER

                            Genrated Files For CROSS arch64 arm build:
                            /build_cross_compile/bin/
                                     /stripped/HPC_CLIENT_APP
                                     /unstripped/GDCU_SERVER


./start_up.sh              -> script to find dependent libraries and store them to repective folders
                           
                           /build/GDCU_LIBS     : contains files related to GDCU server
                           /build/HPC_LIBS      : contains files related to HPC client
