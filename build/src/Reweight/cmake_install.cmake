# Install script for directory: /root/software/nuisance/src/Reweight

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/root/software/nuisance/build/Linux")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RELWITHDEBINFO")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE STATIC_LIBRARY FILES "/root/software/nuisance/build/src/Reweight/libReweight.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/root/software/nuisance/src/Reweight/GlobalDialList.h"
    "/root/software/nuisance/src/Reweight/FitWeight.h"
    "/root/software/nuisance/src/Reweight/WeightEngineBase.h"
    "/root/software/nuisance/src/Reweight/WeightUtils.h"
    "/root/software/nuisance/src/Reweight/SampleNormEngine.h"
    "/root/software/nuisance/src/Reweight/LikelihoodWeightEngine.h"
    "/root/software/nuisance/src/Reweight/SplineWeightEngine.h"
    "/root/software/nuisance/src/Reweight/NUISANCESyst.h"
    "/root/software/nuisance/src/Reweight/NUISANCEWeightEngine.h"
    "/root/software/nuisance/src/Reweight/NUISANCEWeightCalcs.h"
    "/root/software/nuisance/src/Reweight/weightRPA.h"
    "/root/software/nuisance/src/Reweight/MINERvAWeightCalcs.h"
    "/root/software/nuisance/src/Reweight/GENIEWeightEngine.h"
    )
endif()

