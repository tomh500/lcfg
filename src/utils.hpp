#ifndef lcfg_UTILS
#define lcfg_UTILS

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
#include <cmath>
#include <format>
#include <lua.hpp>
#include "include/argh.h"
#include "include/Global.h"
using namespace std;
namespace fs = filesystem;

#include <fstream>
#include <string>
#include <iostream>




string getCurrentTimeString()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::tm *localTime = std::localtime(&in_time_t);
    std::ostringstream oss;
    oss << '['
        << std::setw(2) << std::setfill('0') << localTime->tm_hour << ':'
        << std::setw(2) << std::setfill('0') << localTime->tm_min << ':'
        << std::setw(2) << std::setfill('0') << localTime->tm_sec << ']';
    return oss.str();
}
void log(const string &s)
{
    cerr << getCurrentTimeString() << " " << s << endl;
}

// 定义
const double sensitivity = 2.2;
const double m_yaw = 0.022;
const double m_pitch = 0.022;
const int TICKRATE = 64;
const size_t LENLIMIT = 128;
const size_t LINELIMIT = 300;
const double max_yaw_speed = 300;
const double max_pitch_speed = 45;

extern lua_State* luaL;

string genList(const string &name, const vector<string> &ls)
{
    if (ls.empty())
        return format("alias {} \"\"", name);
    if (ls.size() == 1u)
        return format("alias {} {}", name, ls[0]);
    string res = "";
    for (const auto &s : ls)
    {
        if (!res.empty())
            res += ";";
        res += s;
    }
    return format("alias {} \"{}\"", name, res);
}
size_t getListLen(const vector<string> &ls)
{
    size_t ret = 0;
    for (const auto &s : ls)
    {
        ret += s.size();
    }
    return ret;
}

namespace lcfgProxy
{

string REC_SENS = "rec_sensitivity";
string TICKER = "sq_sf";
string SEQ_PRE = "Sma_Seq_";
string PKG_PRE = "hzSche_pkg_";
string STOP = "smartactive_stop;alias sq_sf Sma_Seq_1";
string LOCKMOUSE = "hzSche_lockmouse";
string UNLOCKMOUSE = "hzSche_unlockmouse";
string WASDCANCEL = "hzSche_wasdCancel";
    vector<pair<string, string>> additional_files;
    void add_file(string name,string content){
        additional_files.push_back(make_pair(name,content));
    }
    string proxy(const string &s)
    {
        return s;
    }
}

namespace ARG
{
    argh::parser cmdl;
    void outUsage()
    {
        cout << "Usage: lcfg <your_script_file_here>";
        exit(0);
    }
    void init(int argc, char *argv[])
    {
        cmdl = argh::parser(argc, argv);
   // if (cmdl.pos_args().size() == 0)
            // outUsage();
        if (cmdl[{"-h", "-help"}])
            outUsage();
        if (cmdl[{"-hz"}])
        {

    lcfgProxy::REC_SENS = "hzCVAR_sens";
    lcfgProxy::TICKER = "hzSche_t";
    lcfgProxy::SEQ_PRE = "hzSche_seq_";
    lcfgProxy::PKG_PRE = "hzSche_pkg_";
    lcfgProxy::STOP = "hzSche_stop_t";
    lcfgProxy::LOCKMOUSE = "hzSche_lockmouse";
    lcfgProxy::UNLOCKMOUSE = "hzSche_unlockmouse";
    lcfgProxy::WASDCANCEL = "hzSche_wasdCancel";



        }

        if (cmdl[{"-buildbhop"}]){
            if(generateBhopFile()==1){std::cerr<<"building bunnyhop file...saved to _init_.cfg\n";};
            FlagDevicesWithReg();
            exit(0);

        }
    }
}

// 事件列表
class eventList
{
    map<int, vector<string>> ls;
    int curT;
    fs::path execpath;
    bool execpath_set;

    class Gen
    {
        int N;
        int linecnt = 0;
        ofstream fout;
        fs::path root, exec;
        void newpage()
        {
            N++;
            linecnt = 0;
            string nxtpage = format("cmd_{}.cfg", N);
            if (N > 1)
                fout << format("exec {}", (exec / nxtpage).string());
            fout = ofstream((root / nxtpage).string(), ios::out | ios::binary);
        }
        void remove_cmd_files(const fs::path &root)
        {
            if (!fs::exists(root) || !fs::is_directory(root))
                return;

            std::regex pattern(R"(cmd_\d+\.cfg)");

            for (const auto &entry : fs::directory_iterator(root))
            {
                if (fs::is_regular_file(entry.status()))
                {
                    const std::string filename = entry.path().filename().string();
                    if (std::regex_match(filename, pattern))
                    {
                        fs::remove(entry.path());
                    }
                }
            }
        }

    public:
        void init(fs::path workspace, fs::path execpath)
        {
            root = workspace;
            exec = execpath;
            remove_cmd_files(root);
            fs::create_directories(root);
            log("workspace: " + root.string());
            N = 0;
            newpage();
        }
        void append(const string &s)
        {
            linecnt++;
            fout << s << endl;
            if (linecnt >= LINELIMIT)
                newpage();
        }
    } gen;
    class AliasChain
    {
        string cur;
        int idN;
        Gen *gen;

    public:
        void newalias(bool secon = true)
        {
            idN++;
            if (idN > 1)
            {
                if (secon)
                    cur += ";";
                cur += format("{}{}\"", lcfgProxy::SEQ_PRE, idN);
                gen->append(cur);
            }
            cur = format("alias {}{} \"", lcfgProxy::SEQ_PRE, idN);
        }
        void init(Gen *ptr)
        {
            gen = ptr;
            idN = 0;
            cur = "";
            newalias();
        }
        void append(const string &s)
        {
            string apd = "";
            if (cur.back() != '"')
                apd += ";";
            apd += s;
            if (cur.size() + apd.size() + 1 > LENLIMIT)
            {
                newalias();
                cur += s;
            }
            else
            {
                cur += apd;
            }
        }
        void sleep(int tick)
        {
            if (cur.back() != '"')
                cur += ";";
            for (int i = 1; i <= tick; i++)
            {
                cur += format("alias {} ", lcfgProxy::TICKER);
                if (cur.size() >= LENLIMIT)
                    newalias(false);
            }
            if (cur.back() != '"')
                newalias(false);
        }
        void end()
        {
            cur += '"';
            gen->append(cur);
        }
    } aliaschain;

public:
    eventList() : execpath("tmpdir"), execpath_set(false) {}
    void setExecPath(const string &s)
    {
        execpath_set = 1;
        execpath = fs::path(s);
    }
    void sleep(int tick)
    {
        curT += tick;
    }
    void pushEvent(const string &s)
    {
        ls[curT].push_back(s);
    }
    int time()
    {
        return curT;
    }
    bool getExecPath_set() const
    {
        return execpath_set;
    }
    void generate(fs::path workspace, lua_State *L)
    {
        if (!execpath_set)
            lua_warning(L, "exec path has not been set! Are you sure?", 0);
        gen.init(workspace, execpath);
        int idN = 0;

        // add hz_stop
        if (ls.empty())
            ls[0].push_back(lcfgProxy::STOP), ls[0].push_back(" ");
        else
            ls[ls.rbegin()->first + 1].push_back(lcfgProxy::STOP),ls.rbegin()->second.push_back(" ");
        // split command blocks into ids
        for (auto &[t, cmdls] : ls)
        {
            vector<string> idls;
            vector<string> cache;
            for (auto &s : cmdls)
            {
                if (getListLen(cache) + s.size() > LENLIMIT - lcfgProxy::PKG_PRE.size() - 9 && getListLen(cache) > 0)
                {
                    idN++;
                    const auto &cmd = genList(lcfgProxy::PKG_PRE + to_string(idN), cache);
                    cache.clear();
                    gen.append(cmd);
                    idls.push_back(format("{}{}", lcfgProxy::PKG_PRE, idN));
                }
                cache.push_back(s);
            }
            if (!cache.empty())
            {
                idN++;
                const auto &cmd = genList(lcfgProxy::PKG_PRE + to_string(idN), cache);
                gen.append(cmd);
                idls.push_back(format("{}{}", lcfgProxy::PKG_PRE, idN));
            }
            cmdls = idls;
        }

        // gen real sequence
        aliaschain.init(&gen);
        for (auto it = ls.begin(); it != ls.end(); it++)
        {
            for (auto &s : it->second)
            {
                aliaschain.append(s);
            }
            if (next(it) != ls.end())
            {
                aliaschain.sleep(next(it)->first - it->first);
            }
        }
        aliaschain.end();

        // gen additional files
    if (!ARG::cmdl[{"-hz"}]) {
        lcfgProxy::add_file("_init_.cfg", format("alias sq_smartactive\nexec {}/cmd_1.cfg\nalias sq_sf Sma_Seq_1", execpath.string()));
        }

        for(auto& [name,content]:lcfgProxy::additional_files){
            ofstream fout((workspace/name).string(), ios::out | ios::binary);
            fout<<content;
            fout.close();
        }
    }
} event;


#endif