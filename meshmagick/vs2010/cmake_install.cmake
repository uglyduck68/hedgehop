# Install script for directory: D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/meshmagick")
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
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/vs2010/Debug/meshmagick.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/vs2010/Release/meshmagick.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/vs2010/MinSizeRel/meshmagick.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/vs2010/RelWithDebInfo/meshmagick.exe")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/vs2010/Debug/meshmagick_lib.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/vs2010/Release/meshmagick_lib.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/vs2010/MinSizeRel/meshmagick_lib.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/vs2010/RelWithDebInfo/meshmagick_lib.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files/meshmagick/include/meshmagick/MeshMagick.h;C:/Program Files/meshmagick/include/meshmagick/MeshMagickPrerequisites.h;C:/Program Files/meshmagick/include/meshmagick/MmEditableBone.h;C:/Program Files/meshmagick/include/meshmagick/MmEditableMesh.h;C:/Program Files/meshmagick/include/meshmagick/MmEditableSkeleton.h;C:/Program Files/meshmagick/include/meshmagick/MmInfoToolFactory.h;C:/Program Files/meshmagick/include/meshmagick/MmInfoTool.h;C:/Program Files/meshmagick/include/meshmagick/MmMeshMergeToolFactory.h;C:/Program Files/meshmagick/include/meshmagick/MmMeshMergeTool.h;C:/Program Files/meshmagick/include/meshmagick/MmMeshUtils.h;C:/Program Files/meshmagick/include/meshmagick/MmOgreEnvironment.h;C:/Program Files/meshmagick/include/meshmagick/MmOptimiseToolFactory.h;C:/Program Files/meshmagick/include/meshmagick/MmOptimiseTool.h;C:/Program Files/meshmagick/include/meshmagick/MmOptionsParser.h;C:/Program Files/meshmagick/include/meshmagick/MmRenameToolFactory.h;C:/Program Files/meshmagick/include/meshmagick/MmRenameTool.h;C:/Program Files/meshmagick/include/meshmagick/MmStatefulMeshSerializer.h;C:/Program Files/meshmagick/include/meshmagick/MmStatefulSkeletonSerializer.h;C:/Program Files/meshmagick/include/meshmagick/MmToolFactory.h;C:/Program Files/meshmagick/include/meshmagick/MmTool.h;C:/Program Files/meshmagick/include/meshmagick/MmToolManager.h;C:/Program Files/meshmagick/include/meshmagick/MmToolUtils.h;C:/Program Files/meshmagick/include/meshmagick/MmTransformToolFactory.h;C:/Program Files/meshmagick/include/meshmagick/MmTransformTool.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Program Files/meshmagick/include/meshmagick" TYPE FILE FILES
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MeshMagick.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MeshMagickPrerequisites.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmEditableBone.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmEditableMesh.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmEditableSkeleton.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmInfoToolFactory.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmInfoTool.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmMeshMergeToolFactory.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmMeshMergeTool.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmMeshUtils.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmOgreEnvironment.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmOptimiseToolFactory.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmOptimiseTool.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmOptionsParser.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmRenameToolFactory.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmRenameTool.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmStatefulMeshSerializer.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmStatefulSkeletonSerializer.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmToolFactory.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmTool.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmToolManager.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmToolUtils.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmTransformToolFactory.h"
    "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/include/MmTransformTool.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/vs2010/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "D:/Lib/OgreSDK_vc10_v1-9-0/addon/meshmagick/vs2010/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
