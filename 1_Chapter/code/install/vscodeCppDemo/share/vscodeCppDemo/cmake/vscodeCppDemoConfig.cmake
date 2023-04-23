# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_vscodeCppDemo_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED vscodeCppDemo_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(vscodeCppDemo_FOUND FALSE)
  elseif(NOT vscodeCppDemo_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(vscodeCppDemo_FOUND FALSE)
  endif()
  return()
endif()
set(_vscodeCppDemo_CONFIG_INCLUDED TRUE)

# output package information
if(NOT vscodeCppDemo_FIND_QUIETLY)
  message(STATUS "Found vscodeCppDemo: 0.0.0 (${vscodeCppDemo_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'vscodeCppDemo' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${vscodeCppDemo_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(vscodeCppDemo_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${vscodeCppDemo_DIR}/${_extra}")
endforeach()
