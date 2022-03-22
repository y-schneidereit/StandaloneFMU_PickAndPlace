cmake_minimum_required (VERSION 3.2)

project (simulator)

add_executable(simulator
  include/fmi2Functions.h
  include/fmi2FunctionTypes.h
  include/fmi2TypesPlatform.h
  include/FMI.h
  include/FMI2.h
  include/util.h
  include/config.h
  include/model.h
  include/cosimulation.h
  include/FMI.c
  include/FMI2.c
  include/fmi2Functions.c
  include/model.c
  include/cosimulation.c
  src/simulator.c
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
