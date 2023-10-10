add_executable( my_app_lib_test main.cpp 
  data.cpp data2.cpp)
target_link_libraries( my_app_lib_test GTest::gtest)

add_test(NAME my_app_lib_test COMMAND $<TARGET_FILE:my_app_lib_test>)

include(GoogleTest)
gtest_discover_tests(my_app_lib_test)