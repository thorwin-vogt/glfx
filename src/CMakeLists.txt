cmake_minimum_required(VERSION 3.16.0)

project(glfx)

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

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

IF(WIN32)
    include_directories("./../include" )
ELSEIF(UNIX)
    include_directories( "./../include" )
ENDIF(WIN32)

find_package(Qt5 COMPONENTS Gui REQUIRED)

add_library( glfx SHARED ${GRAMMAR_FILES} ${HEADER_FILES} ${SOURCE_FILES} )
add_library( glfx_static STATIC ${GRAMMAR_FILES} ${HEADER_FILES} ${SOURCE_FILES} )

IF(WIN32)
set_target_properties( glfx PROPERTIES COMPILE_FLAGS "-DWIN32 -DUNICODE -D_UNICODE -DGLFX_BUILD" )
set_target_properties( glfx_static PROPERTIES COMPILE_FLAGS "-DWIN32 -DUNICODE -D_UNICODE -DGLFX_BUILD -DGLFX_STATIC")
ELSEIF(UNIX)
set_target_properties( glfx PROPERTIES COMPILE_FLAGS "-DLINUX -DUNICODE -D_UNICODE -DGLFX_BUILD" )
set_target_properties( glfx_static PROPERTIES COMPILE_FLAGS "-DLINUX -DUNICODE -D_UNICODE -DGLFX_BUILD -DGLFX_STATIC")
ENDIF(WIN32)

target_link_libraries(glfx Qt5::Gui)
target_link_libraries(glfx_static Qt5::Gui)

IF(NOT WIN32)
INSTALL(FILES ./../include/gl/glfx.h DESTINATION ${INCLUDE_INSTALL_DIR})
INSTALL(FILES ${CMAKE_BINARY_DIR}/src/libglfx_static.a DESTINATION ${LIB_DESTINATION})
INSTALL(FILES ${CMAKE_BINARY_DIR}/src/libglfx.so DESTINATION ${LIB_DESTINATION})
ENDIF(NOT WIN32)
