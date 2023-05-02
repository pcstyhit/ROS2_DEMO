# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_cppBaseMsgPub_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED cppBaseMsgPub_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(cppBaseMsgPub_FOUND FALSE)
  elseif(NOT cppBaseMsgPub_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(cppBaseMsgPub_FOUND FALSE)
  endif()
  return()
endif()
set(_cppBaseMsgPub_CONFIG_INCLUDED TRUE)

# output package information
if(NOT cppBaseMsgPub_FIND_QUIETLY)
  message(STATUS "Found cppBaseMsgPub: 0.0.0 (${cppBaseMsgPub_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'cppBaseMsgPub' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${cppBaseMsgPub_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(cppBaseMsgPub_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${cppBaseMsgPub_DIR}/${_extra}")
endforeach()
