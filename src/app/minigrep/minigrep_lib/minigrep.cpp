#include "minigrep.hpp"

#include <cassert>
#include <iostream>

namespace minigrep {
    void run(Config const & config) {
        assert(not config.query.empty());
        assert(not config.input_file_path.empty());
        std::cout << "minigrep::run" << std::endl;
    }
}