# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(GDCU_SERVER LANGUAGES CXX)

# Set C++ standard (e.g., C++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include source files
set(SOURCES
    gdcu.cpp
    main.cpp
)

# Add the executable target
add_executable(GDCU_SERVER ${SOURCES})

# Set output directory for binaries (unstripped by default)
set_target_properties(GDCU_SERVER PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/unstripped
)

# Add a post-build command to strip the binary and place it in /bin/stripped
add_custom_command(
    TARGET GDCU_SERVER
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/bin/stripped
    # Copy the unstripped binary to the unstripped folder
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:GDCU_SERVER> ${CMAKE_BINARY_DIR}/bin/unstripped/
    # Strip the binary and copy to the stripped folder
    COMMAND ${CMAKE_STRIP} --strip-unneeded $<TARGET_FILE:GDCU_SERVER>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:GDCU_SERVER> ${CMAKE_BINARY_DIR}/bin/stripped/
    COMMENT "Stripping binary and placing it in /bin/stripped"
)