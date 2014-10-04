# Install script for directory: C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/SkyX/cmake_install.cmake")
  include("C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/SkyXDemo1/cmake_install.cmake")
  include("C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/SkyXDemo2/cmake_install.cmake")
  include("C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/SkyXDemo3/cmake_install.cmake")
  include("C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/CMake/cmake_install.cmake")
  include("C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/SkyXCommon/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
