set(MODULE_NAME mimas)
# --------------------------------------------------------------

include_directories(include)

# --------------------------------------------------------------
#  module
# --------------------------------------------------------------
add_custom_target(${MODULE_NAME} true)

# --------------------------------------------------------------
#  src (module/core.so, msgpack.a, lua, lua_dump.a, time_ref.a
# --------------------------------------------------------------
add_subdirectory(src)

# --------------------------------------------------------------
#  module_bind                                   
# --------------------------------------------------------------
file(GLOB MODULE_HEADERS include/${MODULE_NAME}/*.h bind/*.h)
add_custom_target("${MODULE_NAME}_bind"
  COMMAND lua bind.lua
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  DEPENDS ${MODULE_HEADERS} bind.lua)

# --------------------------------------------------------------
#  install                                     
# --------------------------------------------------------------
install(DIRECTORY lubyk
  DESTINATION lib
)                                  
