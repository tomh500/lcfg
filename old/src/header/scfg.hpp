
#include <bits/stdc++.h>

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
