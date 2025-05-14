# Specify the target system
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Specify the cross-compiler
set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)

# Specify the sysroot if available (replace with the actual sysroot path)
# If you have an NXP BSP or SDK, use its sysroot
##set(CMAKE_SYSROOT /path/to/s32g3/sysroot)

# Configure CMake's behavior for library and include paths
set(CMAKE_FIND_ROOT_PATH /path/to/s32g3/sysroot)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)