add_executable (InPost "src/main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET InPost PROPERTY CXX_STANDARD 20)
endif()

