add_executable (PclusterTest "ExampleTest.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PclusterTest PROPERTY CXX_STANDARD 20)
endif()

include(FetchContent)

#GTEST
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

target_link_libraries(PclusterTest PRIVATE 
	Pcluster
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(PclusterTest)