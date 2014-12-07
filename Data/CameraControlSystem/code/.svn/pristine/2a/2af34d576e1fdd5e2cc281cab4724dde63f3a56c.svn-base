message( "Building Demos" )

project(CCSdemo)

SET( CCS_PATH_TO_OGRE_EXAMPLE_FRAMEWORK CACHE FILEPATH "Path to Ogre Example Framework, usually in Ogre SDK." )

FIND_PACKAGE(OIS)

IF(OIS_FOUND)
    SET( CCS_DEMO_INCLUDES ${CCS_DEMO_INCLUDES} ${OIS_INCLUDE_DIRS} )
ENDIF(OIS_FOUND)

SET( CCS_DEMO_INCLUDES ${CCS_DEMO_INCLUDES} ${CCS_PATH_TO_OGRE_EXAMPLE_FRAMEWORK} "../CameraControlSystem/include/" )

MARK_AS_ADVANCED(
    CCS_PATH_TO_OGRE_EXAMPLE_FRAMEWORK
    CCS_DEMO_INCLUDES
)

include_directories( ${CCS_DEMO_INCLUDES} )

link_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../CameraControlSystem/ ${CCS_PATH_TO_LIBRARIES} )

add_executable( CCSDemo${SUFF} src/DummyCameraMode.h src/main.cpp )

target_link_libraries( CCSDemo${SUFF} CCS${SUFF}  ${OIS_LIBRARIES} ${OGRE_LIBRARIES} )

#message("CMAKE_INSTALL_PREFIX : ${CMAKE_INSTALL_PREFIX}")

install(TARGETS CCSDemo${SUFF}
	RUNTIME DESTINATION bin
	)

install(FILES src/DummyCameraMode.h DESTINATION include/CCS/CCS_demo)

