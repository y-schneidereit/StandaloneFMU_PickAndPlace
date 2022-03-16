cmake_minimum_required (VERSION 3.2)

project (simulator)

add_executable(simulator
  include/fmi2Functions.h
  include/fmi2FunctionTypes.h
  include/fmi2TypesPlatform.h
  src/simulator.c)

target_include_directories(simulator PUBLIC
  include
)

set(FMU_INCLUDE_DIR include)
# searching for include directory
find_path(FMU_INCLUDE_DIR fmi2Functions.h)

set(FMU_LIBRARY PickAndPlace/binaries/win64)
# searching for library file
find_library(FMU_LIBRARY msfmu)

include_directories(${FMU_INCLUDE_DIR})
set(YOUR_LIBRARIES ${YOUR_LIBRARIES} ${FMU_LIBRARY})
target_link_libraries(simulator ${YOUR_LIBRARIES})


if (MSVC)
  add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
  target_link_libraries(simulator shlwapi.lib)
endif ()

if (UNIX)
  target_link_libraries(simulator m ${CMAKE_DL_LIBS})
endif (UNIX)
