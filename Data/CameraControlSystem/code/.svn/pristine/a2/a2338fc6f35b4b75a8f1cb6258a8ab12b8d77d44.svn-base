include_directories(include)

include_directories(${CCS_PATH_TO_OGRE_INCLUDE})

IF( CCS_BUILD_STATIC )
    message( "Building as static" )
    SET( CCS_LIBRARY_TYPE STATIC )
ELSE()
    message( "Building as shared" )
    SET( CCS_LIBRARY_TYPE SHARED )
ENDIF()

add_library ( CCS${SUFF} ${CCS_LIBRARY_TYPE}
    src/CCSBasicCameraModes.cpp
    src/CCSCameraControlSystem.cpp
    src/CCSFreeCameraMode.cpp
    src/CCSOrbitalCameraMode.cpp
    src/CCSPrerequisites.cpp
    src/CCSSphericCameraMode.cpp
)


# install library
install(TARGETS CCS${SUFF}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)

# Install headers
file(GLOB CSS_COMMON_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
install(FILES ${CSS_COMMON_HEADERS}
		DESTINATION include/CCS)

