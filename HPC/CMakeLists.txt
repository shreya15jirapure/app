cmake_minimum_required(VERSION 3.10)

# Project name and languages
project(HPC_CLIENT_APP LANGUAGES C CXX)

# Gather all .c files in the current directory
file(GLOB C_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

# Include source files
set(SOURCES
    ${C_SOURCES}
)

# Add executable
add_executable(HPC_CLIENT_APP ${SOURCES})

# Set output directory for binaries (unstripped by default)
set_target_properties(HPC_CLIENT_APP PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/unstripped
)

# Add a post-build command to strip the binary and place it in /bin/stripped
add_custom_command(
    TARGET HPC_CLIENT_APP
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/bin/stripped
    # Copy the unstripped binary to the unstripped folder
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:HPC_CLIENT_APP> ${CMAKE_BINARY_DIR}/bin/unstripped/
    # Strip the binary and copy to the stripped folder
    COMMAND ${CMAKE_STRIP} --strip-unneeded $<TARGET_FILE:HPC_CLIENT_APP>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:HPC_CLIENT_APP> ${CMAKE_BINARY_DIR}/bin/stripped/
    COMMENT "Stripping binary and placing it in /bin/stripped"
)