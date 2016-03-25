# Copyright (c) 2016 Flokart World, Inc.
# All rights reserved.
cmake_minimum_required (VERSION 3.0.0)
find_package (CMakeSupports REQUIRED 0.0.6)
project (hellowww)

CMS_BEGIN(Executable HelloWWW)
  CMS_IMPORT_PACKAGE(Boost REQUIRED)
  CMS_IMPORT_PACKAGE(OpenSSL PREFIX OPENSSL REQUIRED)

  # They don't define cached variables.
  find_package (libpion REQUIRED)
  CMS_INCLUDE_DIRECTORIES(${LIBPION_INCLUDE_DIRS})
  CMS_LINK_LIBRARIES(${LIBPION_LIBRARIES})

  CMS_ADD_SOURCE_FILES(server.cpp
                       server.hpp
                       main.cpp
                       wwwmain.cpp
                       wwwmain.hpp)

  if (MSVC)
    CMS_ADD_DEFINITIONS(_CRT_SECURE_NO_WARNINGS)
    CMS_DISABLE_MSVC_WARNINGS(4251)
  endif ()
CMS_END()
