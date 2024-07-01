# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_gl_ros2_driver_udp_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED gl_ros2_driver_udp_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(gl_ros2_driver_udp_FOUND FALSE)
  elseif(NOT gl_ros2_driver_udp_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(gl_ros2_driver_udp_FOUND FALSE)
  endif()
  return()
endif()
set(_gl_ros2_driver_udp_CONFIG_INCLUDED TRUE)

# output package information
if(NOT gl_ros2_driver_udp_FIND_QUIETLY)
  message(STATUS "Found gl_ros2_driver_udp: 0.0.0 (${gl_ros2_driver_udp_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'gl_ros2_driver_udp' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${gl_ros2_driver_udp_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(gl_ros2_driver_udp_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${gl_ros2_driver_udp_DIR}/${_extra}")
endforeach()
