#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav_2d_msgs::nav_2d_msgs__rosidl_generator_py" for configuration "Debug"
set_property(TARGET nav_2d_msgs::nav_2d_msgs__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(nav_2d_msgs::nav_2d_msgs__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libnav_2d_msgs__rosidl_generator_py.so"
  IMPORTED_SONAME_DEBUG "libnav_2d_msgs__rosidl_generator_py.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS nav_2d_msgs::nav_2d_msgs__rosidl_generator_py )
list(APPEND _IMPORT_CHECK_FILES_FOR_nav_2d_msgs::nav_2d_msgs__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libnav_2d_msgs__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
