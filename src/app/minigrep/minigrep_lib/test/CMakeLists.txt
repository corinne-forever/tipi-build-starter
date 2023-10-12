enable_testing()

add_executable(
  minigrep_lib_test
  minigrep.cpp
)
target_link_libraries(
  minigrep_lib_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(minigrep_lib_test)
