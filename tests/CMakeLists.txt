add_executable (InPostTest "ExampleTest.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET InPostTest PROPERTY CXX_STANDARD 20)
endif()


target_link_libraries(InPostTest PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(InPostTest)