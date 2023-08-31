# Install script for directory: /root/software/nuisance/app

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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuismin" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuismin")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuismin"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/nuismin")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuismin" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuismin")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuismin"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuismin")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuis_flat_tree_combiner" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuis_flat_tree_combiner")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuis_flat_tree_combiner"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/nuis_flat_tree_combiner")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuis_flat_tree_combiner" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuis_flat_tree_combiner")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuis_flat_tree_combiner"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuis_flat_tree_combiner")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuiscomp" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuiscomp")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuiscomp"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/nuiscomp")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuiscomp" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuiscomp")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuiscomp"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuiscomp")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisflat" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisflat")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisflat"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/nuisflat")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisflat" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisflat")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisflat"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisflat")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissmear" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissmear")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissmear"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/nuissmear")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissmear" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissmear")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissmear"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissmear")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissyst" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissyst")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissyst"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/nuissyst")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissyst" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissyst")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissyst"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuissyst")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbayes" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbayes")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbayes"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/nuisbayes")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbayes" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbayes")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbayes"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbayes")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbac" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbac")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbac"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/nuisbac")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbac" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbac")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbac"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisbac")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisplot" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisplot")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisplot"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/nuisplot")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisplot" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisplot")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisplot"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuisplot")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGiBUU" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGiBUU")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGiBUU"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/PrepareGiBUU")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGiBUU" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGiBUU")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGiBUU"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGiBUU")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/geniezexp" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/geniezexp")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/geniezexp"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/geniezexp")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/geniezexp" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/geniezexp")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/geniezexp"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/geniezexp")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGENIE" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGENIE")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGENIE"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/PrepareGENIE")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGENIE" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGENIE")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGENIE"
         OLD_RPATH "/opt/root/v6-26-10/lib:/opt/genie/3_02_02/lib:/opt/pythia/6.4.28:/opt/lhapdf/5.9.1/lib:/root/software/nuisance/build/src/Config:/root/software/nuisance/build/src/FCN:/root/software/nuisance/build/src/FitBase:/root/software/nuisance/build/src/InputHandler:/root/software/nuisance/build/src/Logger:/root/software/nuisance/build/src/MCStudies:/root/software/nuisance/build/src/Routines:/root/software/nuisance/build/src/Smearceptance:/root/software/nuisance/build/src/Splines:/root/software/nuisance/build/src/Statistical:/root/software/nuisance/build/src/Utils:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PrepareGENIE")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuishistrange" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuishistrange")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuishistrange"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/software/nuisance/build/app/nuishistrange")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuishistrange" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuishistrange")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuishistrange"
         OLD_RPATH "/opt/root/v6-26-10/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/nuishistrange")
    endif()
  endif()
endif()

