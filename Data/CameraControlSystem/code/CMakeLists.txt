cmake_minimum_required(VERSION 2.6)

PROJECT(CCS)

SET(CCS_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Include necessary submodules
SET( CMAKE_MODULE_PATH
  "${CCS_SOURCE_DIR}/CMake"
  "${CCS_SOURCE_DIR}/CMake/Utils"
  "${CCS_SOURCE_DIR}/CMake/Packages"
)

FIND_PACKAGE(OGRE)

IF(OGRE_FOUND)
    SET( CCS_PATH_TO_OGRE_INCLUDE ${CCS_PATH_TO_OGRE_INCLUDE} ${OGRE_INCLUDE_DIRS} )
    SET( CCS_PATH_TO_LIBRARIES ${CCS_PATH_TO_LIBRARIES} )
    SET( CCS_DEMO_INCLUDES ${CCS_DEMO_INCLUDES} ${CCS_PATH_TO_OGRE_INCLUDE} )
ENDIF(OGRE_FOUND)

if (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(SUFF "_d")
endif()

SET( CCS_BUILD_DEMOS false CACHE BOOL "Build Demos." )
SET( CCS_BUILD_SDK_DEMOS false CACHE BOOL "Build Demos." )
SET( CCS_BUILD_STATIC false CACHE BOOL "Build as static library." )

add_subdirectory(CameraControlSystem)

IF(CCS_BUILD_DEMOS)
    add_subdirectory(CameraControlSystemDemo)
ENDIF(CCS_BUILD_DEMOS)

IF(CCS_BUILD_SDK_DEMOS)
    add_subdirectory(CameraControlSystemSDKDemo)
ENDIF(CCS_BUILD_SDK_DEMOS)

# install find CCS package
install(FILES CMake/Packages/FindCCS.cmake DESTINATION lib/cmake)

