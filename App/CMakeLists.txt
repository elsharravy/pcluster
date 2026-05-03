add_executable (App "src/main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pcluster PROPERTY CXX_STANDARD 20)
endif()

include(FetchContent)

target_link_libraries(App PRIVATE Pcluster)
