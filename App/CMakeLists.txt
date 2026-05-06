add_executable (App "src/main.cpp" )

target_compile_features(App PUBLIC cxx_std_20)

include(FetchContent)

target_link_libraries(App PRIVATE Pcluster)
