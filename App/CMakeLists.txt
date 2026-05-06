add_executable (App "src/main.cpp" )

target_compile_features(App PUBLIC cxx_std_20)

include(FetchContent)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.6.2
)

FetchContent_MakeAvailable(CLI11)

target_link_libraries(App PRIVATE CLI11::CLI11)
target_link_libraries(App PRIVATE Pcluster)
