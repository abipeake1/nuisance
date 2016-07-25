set(CXX_WARNINGS "-Wall ") #-Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_WARNINGS}")

if(DEFINED USE_EXP AND USE_EXP)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fPIC -O3")

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
  set(CURRENT_CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS_DEBUG})
elseif(CMAKE_BUILD_TYPE MATCHES RELEASE)
  set(CURRENT_CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS_RELEASE})
else()
  cmessage(FATAL_ERROR "[ERROR]: Unknown CMAKE_BUILD_TYPE (\"${CMAKE_BUILD_TYPE}\"): Should be \"DEBUG\" or \"RELEASE\".")
endif()

set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} ")
set(CMAKE_DEPENDLIB_FLAGS "${ROOT_LD_FLAGS}")

if(NOT ${RWENGINE_LINKER_FLAGS} STREQUAL "")
  set(CMAKE_DEPENDLIB_FLAGS "${CMAKE_DEPENDLIB_FLAGS} ${RWENGINE_LINKER_FLAGS}")
endif()

if (DEFINED USE_MYPERFTOOLS AND USE_MYPERFTOOLS)
#  add_dependencies(gperftools libunwind)
  set(CMAKE_CXX_FLAGS "-fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free ${CMAKE_CXX_FLAGS}")
  set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} -ltcmalloc_and_profiler")
  cmessage(STATUS "Using google performance libraries")
endif()

if(DEFINED USE_EXP AND USE_EXP)
  set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} -fopenmp")
endif()

if (VERBOSE)
  cmessage (STATUS "C++ Compiler      : " ${CXX_COMPILER_NAME})
  cmessage (STATUS "    flags         : " ${CMAKE_CXX_FLAGS})
  cmessage (STATUS "    Release flags : " ${CMAKE_CXX_FLAGS_RELEASE})
  cmessage (STATUS "    Debug flags   : " ${CMAKE_CXX_FLAGS_DEBUG})
  cmessage (STATUS "    Link Flags    : " ${CMAKE_LINK_FLAGS})
  cmessage (STATUS "    Lib Flags     : " ${CMAKE_DEPENDLIB_FLAGS})
endif()
