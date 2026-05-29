cmake_minimum_required(VERSION 3.10)
project(FSA_Examples)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

set(FSA_INCLUDE_DIR ${PARENT_DIR} CACHE PATH "Directory containing fsav2.h")
include_directories(${FSA_INCLUDE_DIR})

if(WIN32)
    set(FSA_LIB_DIR ${PARENT_DIR})
    set(FSA_LIB_FILE ${PARENT_DIR}/libfsav2.dll.a)
    set(FSA_DLL ${PARENT_DIR}/fsav2.dll)
else()
    set(FSA_LIB_DIR ${PARENT_DIR} CACHE PATH "Directory containing libfsav2.so")
    set(FSA_LIB_FILE ${FSA_LIB_DIR}/libfsav2.so CACHE FILEPATH "Path to libfsav2.so")
    if(NOT EXISTS ${FSA_LIB_FILE})
        message(FATAL_ERROR "${FSA_LIB_FILE} does not exist.")
    endif()
    file(READ ${FSA_LIB_FILE} FSA_LIB_MAGIC OFFSET 0 LIMIT 4 HEX)
    if(NOT FSA_LIB_MAGIC STREQUAL "7f454c46")
        message(FATAL_ERROR
            "${FSA_LIB_FILE} is not an ELF shared library. "
            "It is probably a Git LFS pointer file. Run `git lfs pull` "
            "in fourier_actuator_sdk, or configure with "
            "`-DFSA_LIB_DIR=/path/to/a/directory/containing/the/real/libfsav2.so`.")
    endif()
endif()

file(GLOB EXAMPLE_SOURCES "*.cpp")

foreach(SOURCE_FILE ${EXAMPLE_SOURCES})
    get_filename_component(EXEC_NAME ${SOURCE_FILE} NAME_WE)
    
    add_executable(${EXEC_NAME} ${SOURCE_FILE})
    
    if(WIN32)
        target_link_libraries(${EXEC_NAME} ${FSA_LIB_FILE})
        add_custom_command(TARGET ${EXEC_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${FSA_DLL}
            $<TARGET_FILE_DIR:${EXEC_NAME}>)
    else()
        target_link_libraries(${EXEC_NAME} ${FSA_LIB_FILE} Threads::Threads)
        set_target_properties(${EXEC_NAME} PROPERTIES
            INSTALL_RPATH "${FSA_LIB_DIR}"
            BUILD_WITH_INSTALL_RPATH TRUE)
    endif()
endforeach()

message(STATUS "Found examples: ${EXAMPLE_SOURCES}")
message(STATUS "Include directory: ${FSA_INCLUDE_DIR}")
message(STATUS "Library directory: ${FSA_LIB_DIR}")
message(STATUS "Library file: ${FSA_LIB_FILE}")
