include_directories(core/bind)

# --------------------------------------------------------------
#  moc
# --------------------------------------------------------------
file(GLOB SUB_MODULE_HEADERS ../include/mimas/*.h)
list(REMOVE_ITEM SUB_MODULE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/Brush.h)
list(REMOVE_ITEM SUB_MODULE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/Color.h)
list(REMOVE_ITEM SUB_MODULE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/constants.h)
list(REMOVE_ITEM SUB_MODULE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/mimas.h)
list(REMOVE_ITEM SUB_MODULE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/Pen.h)
list(REMOVE_ITEM SUB_MODULE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/Painter.h)
list(REMOVE_ITEM SUB_MODULE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/Path.h)
list(REMOVE_ITEM SUB_MODULE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/qt_config.h)
list(REMOVE_ITEM SUB_MODULE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/range_widget.h)

if(QT_SRC_PATH STREQUAL "")
  set(MOC "moc")
else(QT_SRC_PATH STREQUAL "")
  set(MOC "${QT_SRC_PATH}/bin/moc")
endif(QT_SRC_PATH STREQUAL "")

set(SUB_MODULE_HEADERS_MOC "")
foreach(MOC_SRC ${SUB_MODULE_HEADERS})
  get_filename_component(MOC_SRC_NAME ${MOC_SRC} NAME_WE)
  add_custom_command( PRE_BUILD
    OUTPUT  ${CMAKE_CURRENT_SOURCE_DIR}/moc/${MOC_SRC_NAME}.cpp
    COMMAND ${MOC} ${MOC_SRC} -o ${CMAKE_CURRENT_SOURCE_DIR}/moc/${MOC_SRC_NAME}.cpp
    DEPENDS ${MOC_SRC}
  )
  list(APPEND SUB_MODULE_HEADERS_MOC ${CMAKE_CURRENT_SOURCE_DIR}/moc/${MOC_SRC_NAME}.cpp)
endforeach(MOC_SRC SUB_MODULE_HEADERS)

# --------------------------------------------------------------
#  Qt
#  http://developer.qt.nokia.com/quarterly/view/using_cmake_to_build_qt_projects
# --------------------------------------------------------------
if(QT_SRC_PATH STREQUAL "")
  # build with FindQt4 (non-static build)
  find_package(Qt4 REQUIRED)
  set(QT_USE_QTGUI TRUE)
  set(QT_USE_QTOPENGL TRUE)
  SET(QT_USE_QTOPENGL TRUE)
  include(${QT_USE_FILE})
  add_definitions(${QT_DEFINITIONS})
else(QT_SRC_PATH STREQUAL "")
  if(EXISTS ${QT_SRC_PATH})
  else(EXISTS ${QT_SRC_PATH})
    message("########## Invalid QT_SRC_PATH '${QT_SRC_PATH}'")
  endif(EXISTS ${QT_SRC_PATH})
  set(QT_INCLUDE_PATH ${QT_SRC_PATH}/include)
  set(QT_LIB_PATH ${QT_SRC_PATH}/lib)
  include_directories(${QT_INCLUDE_PATH})
  set(QT_LIBRARIES "-framework Carbon -framework AppKit -framework ApplicationServices ${QT_LIB_PATH}/libQtGui.a ${QT_LIB_PATH}/libQtOpenGL.a ${QT_LIB_PATH}/libQtCore.a /usr/lib/libz.dylib")
endif(QT_SRC_PATH STREQUAL "")

# --------------------------------------------------------------
#  OpenGL
# --------------------------------------------------------------
find_package(OpenGL)

# --------------------------------------------------------------
#  core
# --------------------------------------------------------------
file(GLOB CORE_SOURCES core/bind/dub/*.cpp core/*.cpp core/${PLAT}/*.cpp core/${PLAT}/*.mm moc/*.cpp)
add_library("${MODULE_NAME}_core" MODULE ${CORE_SOURCES})
set_target_properties("${MODULE_NAME}_core"
  PROPERTIES OUTPUT_NAME core
  LINK_FLAGS ${PLAT_OBJ_FLAGS}
  LIBRARY_OUTPUT_DIRECTORY ${LUBYK_LIB}/${MODULE_NAME}
  PREFIX ""
  SUFFIX ".so"
)  
target_link_libraries("${MODULE_NAME}_core"
  ${QT_LIBRARIES}
  ${OPENGL_LIBRARIES}
  glew/vendor/lib/libGLEW.a
)
add_dependencies("${MODULE_NAME}_core" glew_make)

add_dependencies(${MODULE_NAME} "${MODULE_NAME}_core")
