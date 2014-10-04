# Install script for directory: C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/CMake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/SKYX")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/CMake" TYPE FILE FILES
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/CMake/Utils/SkyXFindPkgMacros.cmake"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/CMake/Utils/SkyXConfigTargets.cmake"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/CMake/Utils/SkyXGetVersion.cmake"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/CMake/Utils/SkyXMacroLogFeature.cmake"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/CMake/Templates/VisualStudioUserFile.vcproj.user.in"
    )
endif()

