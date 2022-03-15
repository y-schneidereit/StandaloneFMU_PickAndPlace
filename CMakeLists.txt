cmake_minimum_required (VERSION 3.2)

project (simulator)

add_executable(simulator
  include/fmi2Functions.h
  include/fmi2FunctionTypes.h
  include/fmi2TypesPlatform.h
  
  src/simulator.c
  )

target_include_directories(simulator PUBLIC
  include
  PickAndPlace/binaries/win64/msfmu
)

target_link_libraries(simulator C:/Users/schyan01/git/fmu_pickandplace/PickAndPlace/binaries/win64)

if (MSVC)
  add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
  target_link_libraries(simulator shlwapi.lib)
endif ()

if (UNIX)
  target_link_libraries(simulator m ${CMAKE_DL_LIBS})
endif (UNIX)
