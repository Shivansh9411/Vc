# Install script for directory: /home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/build/libVc.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Vc" TYPE DIRECTORY FILES "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/" FILES_MATCHING REGEX "/*.(h|tcc|def)$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Vc" TYPE FILE FILES
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/Allocator"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/IO"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/Memory"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/SimdArray"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/Utils"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/Vc"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/algorithm"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/array"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/iterators"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/limits"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/simdize"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/span"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/type_traits"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/Vc/vector"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Vc/VcTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Vc/VcTargets.cmake"
         "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/build/CMakeFiles/Export/lib/cmake/Vc/VcTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Vc/VcTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Vc/VcTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Vc" TYPE FILE FILES "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/build/CMakeFiles/Export/lib/cmake/Vc/VcTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Vc" TYPE FILE FILES "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/build/CMakeFiles/Export/lib/cmake/Vc/VcTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Vc" TYPE FILE FILES
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/cmake/UserWarning.cmake"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/cmake/VcMacros.cmake"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/cmake/AddCompilerFlag.cmake"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/cmake/CheckCCompilerFlag.cmake"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/cmake/CheckCXXCompilerFlag.cmake"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/cmake/OptimizeForArchitecture.cmake"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/cmake/FindVc.cmake"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/build/cmake/VcConfig.cmake"
    "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/build/cmake/VcConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/build/tests/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ec2-user/shivansh/kaiju-harness/repos_staging/Vc/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
