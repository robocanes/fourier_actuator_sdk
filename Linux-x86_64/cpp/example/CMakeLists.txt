cmake_minimum_required(VERSION 3.10)
project(FSA_Examples)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

include_directories(${PARENT_DIR})

if(WIN32)
    set(FSA_LIB_DIR ${PARENT_DIR})
    set(FSA_LIB_FILE ${PARENT_DIR}/libfsav2.dll.a)
    set(FSA_DLL ${PARENT_DIR}/fsav2.dll)
else()
    set(FSA_LIB_DIR ${PARENT_DIR})
    set(FSA_LIB_FILE ${PARENT_DIR}/libfsav2.so)
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
        target_link_libraries(${EXEC_NAME} ${FSA_LIB_FILE})
        set_target_properties(${EXEC_NAME} PROPERTIES
            INSTALL_RPATH "${FSA_LIB_DIR}"
            BUILD_WITH_INSTALL_RPATH TRUE)
    endif()
endforeach()

message(STATUS "Found examples: ${EXAMPLE_SOURCES}")
message(STATUS "Library directory: ${FSA_LIB_DIR}")
message(STATUS "Library file: ${FSA_LIB_FILE}")
