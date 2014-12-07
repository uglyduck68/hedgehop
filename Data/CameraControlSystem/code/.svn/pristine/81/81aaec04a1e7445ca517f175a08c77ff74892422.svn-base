message( "Building SDK Demo" )


project(CCS_SDK_DEMO)

SET( CCS_PATH_TO_OGRE_EXAMPLE_FRAMEWORK CACHE FILEPATH "Path to Ogre Example Framework, usually in Ogre SDK." )

FIND_PACKAGE(OIS)

IF(OIS_FOUND)
    SET( CCS_DEMO_INCLUDES ${CCS_DEMO_INCLUDES} ${OIS_INCLUDE_DIRS} )
ENDIF(OIS_FOUND)

SET( CCS_DEMO_INCLUDES ${CCS_DEMO_INCLUDES} ${CCS_PATH_TO_OGRE_EXAMPLE_FRAMEWORK} "../CameraControlSystem/include/" "include/" )

MARK_AS_ADVANCED(
    CCS_PATH_TO_OGRE_EXAMPLE_FRAMEWORK
    CCS_DEMO_INCLUDES
)


include_directories( ${CCS_DEMO_INCLUDES} )

link_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../CameraControlSystem/ ${CCS_PATH_TO_LIBRARIES} )

add_library( CameraControlSystemSDKDemo${SUFF}  include/DummyCameraMode.h src/CameraControlSystemSDKDemo.cpp )

target_link_libraries( CameraControlSystemSDKDemo${SUFF} CCS${SUFF} ${OIS_LIBRARIES} ${OGRE_LIBRARIES})

install(TARGETS CameraControlSystemSDKDemo${SUFF}
	LIBRARY DESTINATION lib/OGRE/Samples/
	ARCHIVE DESTINATION lib/OGRE/Samples/)
	
# Install headers
file(GLOB CSS_SDK_COMMON_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
install(FILES ${CSS_SDK_COMMON_HEADERS}
		DESTINATION include/CCS/CCS_sdkDemo)

