cmake_minimum_required (VERSION 3.2)

project (simulator)

add_executable(simulator
  include/fmi2Functions.h
  include/fmi2FunctionTypes.h
  include/fmi2TypesPlatform.h
  include/FMI.h
  include/FMI2.h
  src/simulator.c
  src/util.h
  src/config.h
)

target_include_directories(simulator PUBLIC
  include
  PickAndPlace
)

if (MSVC)
  add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
  target_link_libraries(simulator shlwapi.lib)
endif ()

if (UNIX)
  target_link_libraries(simulator m ${CMAKE_DL_LIBS})
endif (UNIX)
