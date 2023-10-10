#include "my_app_lib/data.hpp"

#include <iostream>

int main(int argc, char** argv) {
  (void)argc;
  (void)argv;
  std::cout << md::my_app::get_message() << std::endl;
  return 0;
}