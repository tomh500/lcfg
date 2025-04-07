#include "ulti.hpp"
#include <bits/stdc++.h>
using namespace std;

void load(fs::path mainfile)
{
    log("Reading scfg files...");

    string prog=get_raw(mainfile);
    
    log("Done. Formatted code:\n"+add_linenumber(prog));
}

int main(int argc, char *argv[])
{
    // check argc
    if (argc < 2)
    {
        cout << "Usage: scfg.exe <file> <args>" << endl;
        cout << "args:" << endl;
        cout << "--allerror    Treat all warnings as errors, causing the compilation to terminate on any warning.";
        quitf(1);
    }

    // process addtion args
    for (int i = 2; i < argc; i++)
    {
        scfg_args::check_arg(string(argv[i]));
    }

    // get file path
    try_to_access_file(fs::path(string(argv[1])), load, {fs::path("command"), 1});

    quitf(0);
}