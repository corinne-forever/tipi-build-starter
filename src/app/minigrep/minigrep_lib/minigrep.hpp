#pragma once
#include <string>
#include <variant>

namespace minigrep
{
    struct ConfigBuilder;
    
    struct Config
    {
        std::string query;
        std::string input_file_path;

        private:
        friend ConfigBuilder;
        Config() = default;
    };

    struct ConfigBuilder
    {
        std::string query;
        std::string input_file_path;

        std::variant<Config, std::string> build() {
            Config config{};
            if (query.empty()) {
                return "Empty query not allowed.";
            }
            config.query = query;

            if (input_file_path.empty()) {
                return "Empty input_file_path name not allowed.";
            }
            config.input_file_path = input_file_path;
            return config;
            
        }
    };


    void run(Config const & config);
}