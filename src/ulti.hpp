#include <bits/stdc++.h>
using namespace std;
namespace fs = filesystem;

#define PAUSE system("pause")

// file pos
typedef pair<fs::path, int> PosInfo;

// functions
void quitf(int sta);
bool posValid(const PosInfo &pos);
namespace scfg_args
{
    bool allerror;
    void check_arg(const string &arg);
}
void error(const string &text, const PosInfo &pos = PosInfo());
void waring(const string &text, const PosInfo &pos = PosInfo());
template <typename T>
void tryToAccessFile(const fs::path &file, T callback, const PosInfo &pos = PosInfo());

// -------------------------------------------------------------------------------------------

// quit with a status
void quitf(int sta)
{
    exit(sta);
}

// file pos check
bool posValid(const PosInfo &pos)
{
    return !pos.first.empty() && pos.second != 0;
}

// check_arg
void scfg_args::check_arg(const string &arg)
{
    if (arg == "--allerror")
        allerror = 1;
    else
    {
        error(format("unknown argument '{}'", arg));
    }
}

// report an error
void error(const string &text, const PosInfo &pos)
{
    cout << "error:" << endl;
    if (posValid(pos))
        cout << format("in file '{}', at line {}: ", pos.first.string(), pos.second) << endl;
    cout << text << endl;
    quitf(1);
}

// report an waring
void waring(const string &text, const PosInfo &pos)
{
    cout << "error:" << endl;
    if (posValid(pos))
        cout << format("in file '{}', at line {}: ", pos.first.string(), pos.second) << endl;
    cout << text << endl;
    if (scfg_args::allerror)
        quitf(1);
}

// try access files. if success it will call "callback()", or quit with an error
template <typename T>
void tryToAccessFile(const fs::path &file, T callback, const PosInfo &pos)
{
    if (fs::exists(file))
    {
        callback(file);
    }
    else
    {
        error(format("file '{}' does not exist!", file.string()), pos);
    }
}