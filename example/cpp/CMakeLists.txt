cmake_minimum_required(VERSION 3.10)
project(FSA_Examples)

if (MSVC)
    add_compile_options(/utf-8)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

set(THIS_DIR ${CMAKE_CURRENT_LIST_DIR})

get_filename_component(EXAMPLE_DIR ${THIS_DIR} DIRECTORY)

get_filename_component(PROJECT_ROOT ${EXAMPLE_DIR} DIRECTORY)

if (WIN32)

    set(FSA_PLATFORM_CPP_DIR ${PROJECT_ROOT}/Windows-x86_64/cpp)
    set(FSA_LIB_DIR ${FSA_PLATFORM_CPP_DIR})

    set(FSA_LIB_FILE ${FSA_PLATFORM_CPP_DIR}/fsav3.lib)
    set(FSA_DLL_FILE ${FSA_PLATFORM_CPP_DIR}/fsav3.dll)

    set(VC_DLLS
        ${FSA_PLATFORM_CPP_DIR}/msvcp140.dll
        ${FSA_PLATFORM_CPP_DIR}/vcruntime140.dll
        ${FSA_PLATFORM_CPP_DIR}/vcruntime140_1.dll
    )

elseif (UNIX)

    set(FSA_PLATFORM_CPP_DIR ${PROJECT_ROOT}/Linux-x86_64/cpp)
    set(FSA_LIB_DIR ${FSA_PLATFORM_CPP_DIR})
    set(FSA_LIB_FILE ${FSA_PLATFORM_CPP_DIR}/libfsav3.so)

endif()

file(GLOB EXAMPLE_SOURCES "*.cpp")

foreach(SRC ${EXAMPLE_SOURCES})
    get_filename_component(EXE_NAME ${SRC} NAME_WE)

    add_executable(${EXE_NAME} ${SRC})

    target_include_directories(${EXE_NAME}
        PRIVATE
            ${FSA_PLATFORM_CPP_DIR}
    )

    if (WIN32)
        target_link_libraries(${EXE_NAME} ${FSA_LIB_FILE})

        add_custom_command(TARGET ${EXE_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${FSA_DLL_FILE}
            $<TARGET_FILE_DIR:${EXE_NAME}>
        )

        foreach(VC_DLL ${VC_DLLS})
            if (EXISTS ${VC_DLL})
                add_custom_command(TARGET ${EXE_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    ${VC_DLL}
                    $<TARGET_FILE_DIR:${EXE_NAME}>
                )
            endif()
        endforeach()

    elseif (UNIX)
        target_link_libraries(${EXE_NAME}
            ${FSA_LIB_FILE}
            Threads::Threads
        )

        set_target_properties(${EXE_NAME} PROPERTIES
            INSTALL_RPATH "${FSA_LIB_DIR}"
            BUILD_WITH_INSTALL_RPATH TRUE
        )

    endif()
endforeach()

message(STATUS "Found examples: ${EXAMPLE_SOURCES}")
message(STATUS "Project root: ${PROJECT_ROOT}")
message(STATUS "SDK include dir: ${FSA_PLATFORM_CPP_DIR}")
message(STATUS "Library file: ${FSA_LIB_FILE}")
