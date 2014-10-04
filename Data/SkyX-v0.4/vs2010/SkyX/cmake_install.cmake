# Install script for directory: C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX

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
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Release" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/lib/Release/SkyX.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/Release" TYPE SHARED_LIBRARY FILES "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/bin/Release/SkyX.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/RelWithDebInfo" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/lib/RelWithDebInfo/SkyX.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/RelWithDebInfo" TYPE SHARED_LIBRARY FILES "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/bin/RelWithDebInfo/SkyX.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/MinSizeRel" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/lib/MinSizeRel/SkyX.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/MinSizeRel" TYPE SHARED_LIBRARY FILES "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/bin/MinSizeRel/SkyX.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Debug" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/lib/Debug/SkyX_d.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/Debug" TYPE SHARED_LIBRARY FILES "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/vs2010/bin/Debug/SkyX_d.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SKYX" TYPE FILE FILES
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/AtmosphereManager.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/BasicController.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/CloudsManager.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/ColorGradient.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/Controller.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/GPUManager.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/MeshManager.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/MoonManager.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/Prerequisites.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/SkyX.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/VCloudsManager.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SKYX/VClouds" TYPE FILE FILES
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/VClouds/DataManager.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/VClouds/Ellipsoid.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/VClouds/FastFakeRandom.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/VClouds/GeometryBlock.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/VClouds/GeometryManager.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/VClouds/Lightning.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/VClouds/LightningManager.h"
    "C:/uglyduck/Lib/OgreSDK_vc10_v1-9-0/addon/SkyX-v0.4/SkyX/Include/VClouds/VClouds.h"
    )
endif()

