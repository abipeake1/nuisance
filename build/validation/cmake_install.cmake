# Install script for directory: /root/software/nuisance/validation

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-ANL"
    "/root/software/nuisance/validation/nuis-valid-comp-ANL"
    "/root/software/nuisance/validation/nuis-valid-plot-ANL"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-BNL"
    "/root/software/nuisance/validation/nuis-valid-comp-BNL"
    "/root/software/nuisance/validation/nuis-valid-plot-BNL"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-FNAL"
    "/root/software/nuisance/validation/nuis-valid-comp-FNAL"
    "/root/software/nuisance/validation/nuis-valid-plot-FNAL"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-GGM"
    "/root/software/nuisance/validation/nuis-valid-comp-GGM"
    "/root/software/nuisance/validation/nuis-valid-plot-GGM"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-BEBC"
    "/root/software/nuisance/validation/nuis-valid-comp-BEBC"
    "/root/software/nuisance/validation/nuis-valid-plot-BEBC"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-T2K"
    "/root/software/nuisance/validation/nuis-valid-comp-T2K"
    "/root/software/nuisance/validation/nuis-valid-plot-T2K"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-MiniBooNE"
    "/root/software/nuisance/validation/nuis-valid-comp-MiniBooNE"
    "/root/software/nuisance/validation/nuis-valid-plot-MiniBooNE"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-SciBooNE"
    "/root/software/nuisance/validation/nuis-valid-comp-SciBooNE"
    "/root/software/nuisance/validation/nuis-valid-plot-SciBooNE"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-K2K"
    "/root/software/nuisance/validation/nuis-valid-comp-K2K"
    "/root/software/nuisance/validation/nuis-valid-plot-K2K"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-MINERvA"
    "/root/software/nuisance/validation/nuis-valid-comp-MINERvA"
    "/root/software/nuisance/validation/nuis-valid-plot-MINERvA"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-ArgoNeuT"
    "/root/software/nuisance/validation/nuis-valid-comp-ArgoNeuT"
    "/root/software/nuisance/validation/nuis-valid-plot-ArgoNeuT"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/var/validation" TYPE PROGRAM FILES
    "/root/software/nuisance/validation/nuis-valid-gen-MicroBooNE"
    "/root/software/nuisance/validation/nuis-valid-comp-MicroBooNE"
    "/root/software/nuisance/validation/nuis-valid-plot-MicroBooNE"
    )
endif()

