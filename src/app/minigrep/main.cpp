#include "minigrep_lib/minigrep.hpp"

#include <boost/program_options.hpp>
#include <iostream>

minigrep::Config parse_args_or_exit(int argc, char **argv)
{
  namespace po = boost::program_options;
  try
  {
    minigrep::ConfigBuilder config_builder;

    po::options_description desc("Allowed options");
    // clang-format off
    desc.add_options()
      ("help", "Produce help message")
      ("query", po::value<std::string>(&config_builder.query), "Query argument")
      ("input-file", po::value<std::string>(&config_builder.input_file_path), "Input file argument (as path)")
    ;

    po::positional_options_description p;
    p.add("query", 1).add("input-file", 1);

    po::variables_map vm;
    po::store(
      po::command_line_parser(argc, argv)
      .options(desc).positional(p).run(), vm);
    // clang-format on
    po::notify(vm);

    if (vm.count("help"))
    {
      std::cout << desc << "\n";
      std::exit(0);
    }

    auto config = config_builder.build();
    try
    {
      return std::get<minigrep::Config>(config);
    }
    catch (...)
    {
      throw po::error(std::get<std::string>(config));
    }
  }
  catch (po::error const &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    std::exit(1);
  }
}

int main(int argc, char **argv)
{
  auto config = parse_args_or_exit(argc, argv);
  minigrep::run(config);
  return 0;
}