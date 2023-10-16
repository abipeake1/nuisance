# Install script for directory: /Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/abigailpeake/software/nuisance/build/build/Darwin")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/CMessage.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/FindGENIE.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/FindGENIE2.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/FindGENIE3.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/FindGENIEDependencies.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/FindGENIEVersion.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/FindLHAPDF.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/FindNEUT53X.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/FindNEUT54X.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/FindNEUTConfigLegacy.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/FindNuWro.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/FindPythia6.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/Findlog4cpp.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/NEUT.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/NuHepMCModules.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/NuHepMCUtils.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/ParseConfigApps.cmake"
    "/Users/abigailpeake/software/nuisance/build/_deps/cmakemodules-src/ROOT.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/abigailpeake/software/nuisance/build/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
