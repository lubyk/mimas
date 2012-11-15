# --------------------------------------------------------------
#  mimas_core                                  mimas/core.so
# --------------------------------------------------------------
set(target "${MODULE_NAME}_core")

include_directories(core/bind)

# --------------------------------------------------------------
#  moc
# --------------------------------------------------------------
file(GLOB MODULE_headers ../include/mimas/*.h)
list(REMOVE_ITEM MODULE_headers ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/Brush.h)
list(REMOVE_ITEM MODULE_headers ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/Color.h)
list(REMOVE_ITEM MODULE_headers ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/Cursor.h)
list(REMOVE_ITEM MODULE_headers ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/constants.h)
list(REMOVE_ITEM MODULE_headers ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/mimas.h)
list(REMOVE_ITEM MODULE_headers ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/Pen.h)
list(REMOVE_ITEM MODULE_headers ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/Painter.h)
list(REMOVE_ITEM MODULE_headers ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/Path.h)
list(REMOVE_ITEM MODULE_headers ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/qt_config.h)
list(REMOVE_ITEM MODULE_headers ${CMAKE_CURRENT_SOURCE_DIR}/../include/mimas/range_widget.h)


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

  # --------------------------------------------------------------
  #  Qt moc and settings (non-static)
  # --------------------------------------------------------------
  qt4_wrap_cpp(MODULE_moc ${MODULE_headers})
else(QT_SRC_PATH STREQUAL "")
  if(EXISTS ${QT_SRC_PATH})
  else(EXISTS ${QT_SRC_PATH})
    message("########## Invalid QT_SRC_PATH '${QT_SRC_PATH}'")
  endif(EXISTS ${QT_SRC_PATH})

  # --------------------------------------------------------------
  #  Qt moc and settings (static)
  # --------------------------------------------------------------
  set(MOC "${QT_SRC_PATH}/bin/moc")
  set(MODULE_moc "")
  foreach(MOC_SRC ${MODULE_headers})
    get_filename_component(MOC_SRC_NAME ${MOC_SRC} NAME_WE)
    set(OUT_FILE ${MOC_SRC_NAME}.cpp)
    add_custom_command(PRE_BUILD
      OUTPUT  ${OUT_FILE}
      COMMAND ${MOC} ${MOC_SRC} -o ${OUT_FILE}
      DEPENDS ${MOC_SRC}
    )
    list(APPEND MODULE_moc ${OUT_FILE})
  endforeach(MOC_SRC MODULE_headers)

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
#  glew
# --------------------------------------------------------------
add_subdirectory(glew)

# --------------------------------------------------------------
#  MODULE_src
# --------------------------------------------------------------
file(GLOB MODULE_src core/bind/dub/*.cpp core/bind/*.cpp core/*.cpp core/${PLAT}/*.cpp core/${PLAT}/*.mm)

# --------------------------------------------------------------
#  mimas/core.so
# --------------------------------------------------------------
add_library(${target} MODULE ${MODULE_src} ${MODULE_moc})
set_target_properties(${target}
  PROPERTIES OUTPUT_NAME core
  LINK_FLAGS ${PLAT_OBJ_FLAGS}
  PREFIX ""
  SUFFIX ".so"
)  
target_link_libraries(${target}
  ${QT_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${CMAKE_BINARY_DIR}/glew/libGLEW.a
)
add_dependencies(${target} glew_lib)

add_dependencies(${MODULE_NAME} ${target})

# --------------------------------------------------------------
#  install                                     
# --------------------------------------------------------------
install(TARGETS ${target}
  DESTINATION ${LUBYK_LIB}/lib/${MODULE_NAME}
)

