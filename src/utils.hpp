#ifndef SCFG_UTILS
#define SCFG_UTILS

#include <bits/stdc++.h>
#include <format>
#include <lua.hpp>
#include "include/argh.h"
using namespace std;
namespace fs = filesystem;

#include <fstream>
#include <string>
#include <iostream>

int generateBhopFile() {
    const std::string filename = "_init_.cfg";
    const unsigned char BOM[] = {0xEF, 0xBB, 0xBF};
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Failed to open output file: " << filename << std::endl;
        return 1;
    }

    outFile.write(reinterpret_cast<const char*>(BOM), sizeof(BOM));

    outFile << "alias sq_sf_bhop sma_autobhop_seq_1\n";
    outFile << "alias sqbhop_pkg_1 \"/fps_low;+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_2 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_3 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_4 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_5 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_6 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_7 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_8 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_9 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_10 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_11 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_12 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_13 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_14 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_15 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_16 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_17 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_18 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_19 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_20 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_21 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_22 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_23 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_24 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_25 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_26 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_27 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_28 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_29 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_30 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_31 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_32 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_33 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_34 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_35 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_36 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_37 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_38 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_39 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_40 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_41 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_42 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_43 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_44 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_45 +duck\n";
    outFile << "alias sqbhop_pkg_46 \"-duck;+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_47 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_48 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_49 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_50 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_51 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_52 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_53 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_54 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_55 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_56 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_57 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_58 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_59 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_60 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_61 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_62 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_63 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_64 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_65 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_66 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_67 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_68 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_69 +duck\n";
    outFile << "alias sqbhop_pkg_70 \"-duck;+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_71 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_72 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_73 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_74 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_75 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_76 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_77 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_78 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_79 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_80 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_81 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_82 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_83 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_84 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_85 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_86 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_87 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_88 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_89 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_90 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_91 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_92 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_93 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_94 \"+jump;-jump\"\n";
    outFile << "alias sqbhop_pkg_95 smartactive_stop\n";
    outFile << "alias sma_autobhop_seq_1 \"sqbhop_pkg_1;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_2\"\n";
    outFile << "alias sma_autobhop_seq_2 \"sqbhop_pkg_2;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_3\"\n";
    outFile << "alias sma_autobhop_seq_3 \"sqbhop_pkg_3;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_4\"\n";
    outFile << "alias sma_autobhop_seq_4 \"sqbhop_pkg_4;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_5\"\n";
    outFile << "alias sma_autobhop_seq_5 \"sqbhop_pkg_5;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_6\"\n";
    outFile << "alias sma_autobhop_seq_6 \"sqbhop_pkg_6;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_7\"\n";
    outFile << "alias sma_autobhop_seq_7 \"sqbhop_pkg_7;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_8\"\n";
    outFile << "alias sma_autobhop_seq_8 \"sqbhop_pkg_8;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_9\"\n";
    outFile << "alias sma_autobhop_seq_9 \"sqbhop_pkg_9;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_10\"\n";
    outFile << "alias sma_autobhop_seq_10 \"sqbhop_pkg_10;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_11\"\n";
    outFile << "alias sma_autobhop_seq_11 \"sqbhop_pkg_11;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_12\"\n";
    outFile << "alias sma_autobhop_seq_12 \"sqbhop_pkg_12;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_13\"\n";
    outFile << "alias sma_autobhop_seq_13 \"sqbhop_pkg_13;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_14\"\n";
    outFile << "alias sma_autobhop_seq_14 \"sqbhop_pkg_14;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_15\"\n";
    outFile << "alias sma_autobhop_seq_15 \"sqbhop_pkg_15;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_16\"\n";
    outFile << "alias sma_autobhop_seq_16 \"sqbhop_pkg_16;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_17\"\n";
    outFile << "alias sma_autobhop_seq_17 \"sqbhop_pkg_17;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_18\"\n";
    outFile << "alias sma_autobhop_seq_18 \"sqbhop_pkg_18;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_19\"\n";
    outFile << "alias sma_autobhop_seq_19 \"sqbhop_pkg_19;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_20\"\n";
    outFile << "alias sma_autobhop_seq_20 \"sqbhop_pkg_20;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_21\"\n";
    outFile << "alias sma_autobhop_seq_21 \"sqbhop_pkg_21;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_22\"\n";
    outFile << "alias sma_autobhop_seq_22 \"sqbhop_pkg_22;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_23\"\n";
    outFile << "alias sma_autobhop_seq_23 \"sqbhop_pkg_23;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_24\"\n";
    outFile << "alias sma_autobhop_seq_24 \"sqbhop_pkg_24;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_25\"\n";
    outFile << "alias sma_autobhop_seq_25 \"sqbhop_pkg_25;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_26\"\n";
    outFile << "alias sma_autobhop_seq_26 \"sqbhop_pkg_26;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_27\"\n";
    outFile << "alias sma_autobhop_seq_27 \"sqbhop_pkg_27;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_28\"\n";
    outFile << "alias sma_autobhop_seq_28 \"sqbhop_pkg_28;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_29\"\n";
    outFile << "alias sma_autobhop_seq_29 \"sqbhop_pkg_29;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_30\"\n";
    outFile << "alias sma_autobhop_seq_30 \"sqbhop_pkg_30;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_31\"\n";
    outFile << "alias sma_autobhop_seq_31 \"sqbhop_pkg_31;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_32\"\n";
    outFile << "alias sma_autobhop_seq_32 \"sqbhop_pkg_32;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_33\"\n";
    outFile << "alias sma_autobhop_seq_33 \"sqbhop_pkg_33;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_34\"\n";
    outFile << "alias sma_autobhop_seq_34 \"sqbhop_pkg_34;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_35\"\n";
    outFile << "alias sma_autobhop_seq_35 \"sqbhop_pkg_35;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_36\"\n";
    outFile << "alias sma_autobhop_seq_36 \"sqbhop_pkg_36;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_37\"\n";
    outFile << "alias sma_autobhop_seq_37 \"sqbhop_pkg_37;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_38\"\n";
    outFile << "alias sma_autobhop_seq_38 \"sqbhop_pkg_38;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_39\"\n";
    outFile << "alias sma_autobhop_seq_39 \"sqbhop_pkg_39;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_40\"\n";
    outFile << "alias sma_autobhop_seq_40 \"sqbhop_pkg_40;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_41\"\n";
    outFile << "alias sma_autobhop_seq_41 \"sqbhop_pkg_41;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_42\"\n";
    outFile << "alias sma_autobhop_seq_42 \"sqbhop_pkg_42;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_43\"\n";
    outFile << "alias sma_autobhop_seq_43 \"sqbhop_pkg_43;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_44\"\n";
    outFile << "alias sma_autobhop_seq_44 \"sqbhop_pkg_44;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_45\"\n";
    outFile << "alias sma_autobhop_seq_45 \"sqbhop_pkg_45;alias sq_sf_bhop sma_autobhop_seq_46\"\n";
    outFile << "alias sma_autobhop_seq_46 \"sqbhop_pkg_46;alias sq_sf_bhop alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_47\"\n";
    outFile << "alias sma_autobhop_seq_47 \"sqbhop_pkg_47;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_48\"\n";
    outFile << "alias sma_autobhop_seq_48 \"sqbhop_pkg_48;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_49\"\n";
    outFile << "alias sma_autobhop_seq_49 \"sqbhop_pkg_49;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_50\"\n";
    outFile << "alias sma_autobhop_seq_50 \"sqbhop_pkg_50;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_51\"\n";
    outFile << "alias sma_autobhop_seq_51 \"sqbhop_pkg_51;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_52\"\n";
    outFile << "alias sma_autobhop_seq_52 \"sqbhop_pkg_52;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_53\"\n";
    outFile << "alias sma_autobhop_seq_53 \"sqbhop_pkg_53;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_54\"\n";
    outFile << "alias sma_autobhop_seq_54 \"sqbhop_pkg_54;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_55\"\n";
    outFile << "alias sma_autobhop_seq_55 \"sqbhop_pkg_55;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_56\"\n";
    outFile << "alias sma_autobhop_seq_56 \"sqbhop_pkg_56;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_57\"\n";
    outFile << "alias sma_autobhop_seq_57 \"sqbhop_pkg_57;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_58\"\n";
    outFile << "alias sma_autobhop_seq_58 \"sqbhop_pkg_58;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_59\"\n";
    outFile << "alias sma_autobhop_seq_59 \"sqbhop_pkg_59;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_60\"\n";
    outFile << "alias sma_autobhop_seq_60 \"sqbhop_pkg_60;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_61\"\n";
    outFile << "alias sma_autobhop_seq_61 \"sqbhop_pkg_61;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_62\"\n";
    outFile << "alias sma_autobhop_seq_62 \"sqbhop_pkg_62;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_63\"\n";
    outFile << "alias sma_autobhop_seq_63 \"sqbhop_pkg_63;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_64\"\n";
    outFile << "alias sma_autobhop_seq_64 \"sqbhop_pkg_64;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_65\"\n";
    outFile << "alias sma_autobhop_seq_65 \"sqbhop_pkg_65;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_66\"\n";
    outFile << "alias sma_autobhop_seq_66 \"sqbhop_pkg_66;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_67\"\n";
    outFile << "alias sma_autobhop_seq_67 \"sqbhop_pkg_67;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_68\"\n";
    outFile << "alias sma_autobhop_seq_68 \"sqbhop_pkg_68;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_69\"\n";
    outFile << "alias sma_autobhop_seq_69 \"sqbhop_pkg_69;alias sq_sf_bhop sma_autobhop_seq_70\"\n";
    outFile << "alias sma_autobhop_seq_70 \"alias sq_sf_bhop sma_autobhop_seq_1;sqbhop_pkg_70;alias sq_sf_bhop alias sq_sf_bhop sma_autobhop_seq_2\"\n";

    outFile.close();
    std::cout << "Generated file: " << filename << std::endl;
    return 0;
}


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

lua_State *luaL;

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

namespace SCFGProxy
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

    SCFGProxy::REC_SENS = "hzCVAR_sens";
    SCFGProxy::TICKER = "hzSche_t";
    SCFGProxy::SEQ_PRE = "hzSche_seq_";
    SCFGProxy::PKG_PRE = "hzSche_pkg_";
    SCFGProxy::STOP = "hzSche_stop_t";
    SCFGProxy::LOCKMOUSE = "hzSche_lockmouse";
    SCFGProxy::UNLOCKMOUSE = "hzSche_unlockmouse";
    SCFGProxy::WASDCANCEL = "hzSche_wasdCancel";



        }

        if (cmdl[{"-buildbhop"}]){
            if(generateBhopFile()==1){std::cerr<<"building bunnyhop file...saved to _init_.cfg\n";};
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
            fout = ofstream((root / nxtpage).string(), ios::out);
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
                cur += format("{}{}\"", SCFGProxy::SEQ_PRE, idN);
                gen->append(cur);
            }
            cur = format("alias {}{} \"", SCFGProxy::SEQ_PRE, idN);
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
                cur += format("alias {} ", SCFGProxy::TICKER);
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
            ls[0].push_back(SCFGProxy::STOP), ls[0].push_back(" ");
        else
            ls[ls.rbegin()->first + 1].push_back(SCFGProxy::STOP),ls.rbegin()->second.push_back(" ");
        // split command blocks into ids
        for (auto &[t, cmdls] : ls)
        {
            vector<string> idls;
            vector<string> cache;
            for (auto &s : cmdls)
            {
                if (getListLen(cache) + s.size() > LENLIMIT - SCFGProxy::PKG_PRE.size() - 9 && getListLen(cache) > 0)
                {
                    idN++;
                    const auto &cmd = genList(SCFGProxy::PKG_PRE + to_string(idN), cache);
                    cache.clear();
                    gen.append(cmd);
                    idls.push_back(format("{}{}", SCFGProxy::PKG_PRE, idN));
                }
                cache.push_back(s);
            }
            if (!cache.empty())
            {
                idN++;
                const auto &cmd = genList(SCFGProxy::PKG_PRE + to_string(idN), cache);
                gen.append(cmd);
                idls.push_back(format("{}{}", SCFGProxy::PKG_PRE, idN));
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
        SCFGProxy::add_file("_init_.cfg", format("alias sq_smartactive\nexec {}/cmd_1.cfg\nalias sq_sf Sma_Seq_1", execpath.string()));
        }

        for(auto& [name,content]:SCFGProxy::additional_files){
            ofstream fout((workspace/name).string(),ios::out);
            fout<<content;
            fout.close();
        }
    }
} event;


#endif