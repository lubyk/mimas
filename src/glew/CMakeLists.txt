project(glew)
set(target "glew")

set(GLEW_OUTPUT ${CMAKE_BINARY_DIR}/glew/libGLEW.a)
add_custom_command(
  OUTPUT ${GLEW_OUTPUT}
  COMMAND make
  COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/vendor/lib ${CMAKE_BINARY_DIR}/glew
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/vendor
)
add_custom_target("glew_clean"
  COMMAND make clean
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/vendor
)
add_custom_target("glew_lib" ALL DEPENDS ${GLEW_OUTPUT})

