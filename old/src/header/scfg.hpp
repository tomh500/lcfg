
#include //标准库头文件
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <chrono>
#include <filesystem>


namespace lcfg
{

    namespace fs = std::filesystem;

    class command{
        public:
        std::vector<command> cmdls;
    };

    class lcfg
    {
        fs::path output_file;

    public:
        lcfg(fs::path output_file) : output_file(output_file)
        {
        }

        void gen()
        {
        }
    };
}
