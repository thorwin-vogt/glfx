cmake_minimum_required(VERSION 3.16.0)

FILE( GLOB GRAMMAR_FILES
"glfx.ypp"
"glfx.lpp"
)
SOURCE_GROUP( "Grammar Files" FILES ${GRAMMAR_FILES} )

FILE( GLOB HEADER_FILES
"../include/gl/glfx.h"
"glfxClasses.h"
"glfxParser.h"
"glfxScanner.h"
"glfxLALRParser.hpp"
)
SOURCE_GROUP( "Header Files" FILES ${HEADER_FILES} )

FILE( GLOB SOURCE_FILES
"glfx.cpp"
"glfxLALRParser.cpp"
"glfxScanner.cpp"
)
SOURCE_GROUP( "Source Files" FILES ${SOURCE_FILES} )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS OpenGL REQUIRED)
qt_standard_project_setup()

qt_add_library( glfx SHARED ${GRAMMAR_FILES} ${HEADER_FILES} ${SOURCE_FILES} )
qt_add_library( glfx_static STATIC ${GRAMMAR_FILES} ${HEADER_FILES} ${SOURCE_FILES} )

target_include_directories(glfx
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_include_directories(glfx_static
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

IF(WIN32)
set_target_properties( glfx PROPERTIES COMPILE_FLAGS "-DWIN32 -DUNICODE -D_UNICODE -DGLFX_BUILD" )
set_target_properties( glfx_static PROPERTIES COMPILE_FLAGS "-DWIN32 -DUNICODE -D_UNICODE -DGLFX_BUILD -DGLFX_STATIC")
ELSEIF(UNIX)
set_target_properties( glfx PROPERTIES COMPILE_FLAGS "-DLINUX -DUNICODE -D_UNICODE -DGLFX_BUILD" )
set_target_properties( glfx_static PROPERTIES COMPILE_FLAGS "-DLINUX -DUNICODE -D_UNICODE -DGLFX_BUILD -DGLFX_STATIC")
ENDIF(WIN32)

target_link_libraries(glfx Qt6::OpenGL)
target_link_libraries(glfx_static Qt6::OpenGL)

INSTALL(TARGETS glfx glfx_static
        EXPORT glfxTargets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

INSTALL(EXPORT glfxTargets
        FILE glfxTargets.cmake
        DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/glfx"
        NAMESPACE glfx::)

install(FILES "../include/gl/glfx.h"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/GL
)

INCLUDE(CMakePackageConfigHelpers)
configure_package_config_file(glfxConfig.cmake.in
                              "${CMAKE_CURRENT_BINARY_DIR}/glfxConfig.cmake"
                              INSTALL_DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/glfx"
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/glfxConfig.cmake" DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/glfx")
