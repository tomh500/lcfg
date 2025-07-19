#include "ulti.hpp"
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

using namespace std;

class lcfg_number{
    int number;
public:
    lcfg_number(const string& s){
        if(s.size()==0) error("wrong time format with string '"+s+"'");
        number=0;
        for(size_t i=0;i<s.size();i++){
            if(!isdigit(s[i]))  error("wrong time format with string '"+s+"'");
            number=number*10+(s[i]^48);
        }
    }
};
class lcfg_command{
    typedef variant<lcfg_command,lcfg_number,vector<lcfg_command>> lcfg_args;
    string key_prefix;
    vector<lcfg_args> arg_list;
};



void load(fs::path file)
{
    log("Reading lcfg files...");

    string prog = get_raw(file);

    log("Done. Formatted code:\n" + add_linenumber(prog));

    log("Process \\c -> id");

    sanitize_string(prog);

    log("Done.");

    //begin
    
}

int main(int argc, char *argv[])
{
    // check argc
    if (argc < 2)
    {
        cout << "Usage: lcfg.exe <file> <args>" << endl;
        cout << "args:" << endl;
        cout << "--allerror    Treat all warnings as errors, causing the compilation to terminate on any warning.";
        quitf(1);
    }

    // process addtion args
    for (int i = 2; i < argc; i++)
    {
        lcfg_args::check_arg(string(argv[i]));
    }

    // get file path
    try_to_access_file(fs::path(string(argv[1])), load, {fs::path("command"), 1});

    quitf(0);
}