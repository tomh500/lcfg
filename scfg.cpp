#include <bits/stdc++.h>
#define fi first
#include <format>
#define se second
using namespace std;
string path;
double sen=2.2;
double m_yaw=0.022;
double m_pitch=0.022;
double CVARSLEEP=0;
double tickrate=64;
double ticktime=1/tickrate;
double yawspeed=300;
double pitchspeed=45;
int N=0;
int lineid;

filesystem::path tempdir("Temp");

ofstream fout;
ifstream fin;

pair<double,double> lst(-1,-1);

double tottime=0;

void slp(double x,bool strict=0){
    double L=floor(x*tickrate)/tickrate;
    double R=ceil(x*tickrate)/tickrate;
    if(fabs(x-L)<fabs(x-R)){
        x=L;
    }else{
        x=R;
    }
    x-=0.5/tickrate;
    x=max(x,0.0);
    tottime+=x;
    fout<<endl;
    if(strict){
        fout<<format("alias syncerReg_delay \"incrementvar joy_yaw_sensitivity 0 99999999999999 {:.6f}\"\n",x);
    }else{
        fout<<format("alias syncerReg_delay \"move_begintime_to_yawsen;incrementvar joy_yaw_sensitivity 0 99999999999999 {:.6f}\"\n",tottime);
    }
    fout<<format("alias syncer_callback \"exec {}/{}\"\n",path,++N);
    fout<<"syncer_schedule";
    fout=ofstream(format("Temp/{}.cfg",N),ios::out);
    fout<<"//[generated with scfg]\n\n";
}

void ang(double x,double y,bool needstd=1){
    fout<<format("yaw {:.6f} 1 1\npitch {:.6f} 1 1\n",
        (double)(lst.fi-x)/(sen*m_yaw),
        (double)(y-lst.se)/(sen*m_pitch)
    );
    if(needstd) fout<<"sensitivity 2.2;m_yaw 0.022;m_pitch 0.022\n";

    lst={x,y};

    slp(CVARSLEEP);
    fout<<"hzCVAR_mouse\n";
}

void src(string s){
    fout<<s<<endl;
}

void setang(double x,double y){
    fout<<"yaw 99999999999999999 1 1;\npitch 9999999999999999 1 1;\nsensitivity 2.2;m_yaw 0.022;m_pitch 0.022\n";
    lst={0,0};
    slp(CVARSLEEP);
    ang(x,y,0);
}

void turntoang(double x,double y){
    double dx=x-lst.fi;
    double dy=y-lst.se;

    if(x>lst.fi){
        double res=x-180+(-180-lst.fi);
        if(fabs(res)<fabs(dx)){
            dx=res;
        }
    }else{
        double res=x-(-180)+(180-lst.fi);
        if(fabs(res)<fabs(dx)){
            dx=res;
        }
    }

    // cerr<<dx<<' '<<dy<<endl;

    lst={x,y};

    string sx="";
    string sy="";

    if(dx>0){
        sx="turnleft";
    }else{
        sx="turnright";
    }

    if(dy>0){
        sy="turndown";
    }else{
        sy="turnup";
    }

    double xtime=fabs(dx)/yawspeed;
    double ytime=fabs(dy)/pitchspeed;

    src("+"+sx);
    src("+"+sy);

    if(xtime>ytime) swap(xtime,ytime),swap(sx,sy);

    slp(xtime);

    src("-"+sx);

    slp(ytime-xtime);

    src("-"+sy);
}
void checktime(){
    src("move_begintime_to_yawsen");
    src(format("incrementvar joy_yaw_sensitivity 0 99999999999 {:.6f}",tottime));
    src("multvar joy_yaw_sensitivity -999999999 0 -1");
    src("incrementvar joy_yaw_sensitivity -99999999 0 -100000.0");

    src("syncer_fetch");
    src("syncer_curtime | toggle \"hzScheduler_cmd;joy_pitch_sensitivity\"");
    src("incrementvar joy_pitch_sensitivity -99999999 0 -100000.0");

    src("setinfo -99999999999 =");
    src("joy_yaw_sensitivity | toggle -99999999999");

    src("-99999999999 | incrementvar joy_pitch_sensitivity");
    src("incrementvar joy_pitch_sensitivity -99999999 99999999 200000.0");

    src("setinfo timingError =");
    src("joy_pitch_sensitivity | toggle timingError");
    src("timingError | say");
}

void cvar(string cvarname,string value){
    src(cvarname + " " + value);
}

void play(string path){
    src("play "+path);
}

vector<string> readargs(){
    vector<string> ret(0);
    char c;
    string s="";
    while(1){
        c=fin.get();
        if(c=='\r') continue;
        if(c==EOF){
            if(s!="")   ret.push_back(s);
            return ret;
        }
        if(c=='\n'){
            if(s!="")   ret.push_back(s);
            if(ret.size()==0){
                lineid++;
                continue;
            }
            return ret;
        }
        if(c==' '){
            if(s!=""){
                ret.push_back(s);
                s="";
            }
            continue;
        }
        s+=c;
    }
}
string UnionWithSpace(const vector<string>& ls){
    if(ls.size()==0)    return "";
    string ret=ls[0];
    for(int i=1;i<ls.size();i++){
        ret+=' ';
        ret+=ls[i];
    }
    return ret;
}
string toUpper(const string& s){
    auto ret=s;
    for(int i=0;i<s.size();i++){
        if('a'<=s[i] && s[i]<='z'){
            ret[i]+='A'-'a';
        }
    }
    return ret;
}
template<typename T>
vector<T> popfront(const vector<T>& ls,int N=1){
    auto ret=ls;
    ret.erase(ret.begin(),ret.begin()+N);
    return ret;
}

const int keywordmaxlen=20;
unordered_set<string> keyword;
unordered_set<string> keywordbylen[keywordmaxlen+1];

void deletefile(){
    fin.close();
    fout.close();
    filesystem::remove_all(tempdir);
    // filesystem::remove("run.cfg");
    // for(int i=0;;i++){
    //     ifstream tin(format("{}.cfg",i),ios::in);
    //     if(!tin)    break;
    //     if(tin.eof())   break;
    //     string s;
    //     tin>>s;
    //     tin.close();
    //     if(s!="//[Gen]")    break;
    //     filesystem::remove(format("{}.cfg",i));
    // }
}
void copyfile(){
    filesystem::path program_dir = filesystem::current_path();
    filesystem::path temp_dir = program_dir / "Temp";

    if (!filesystem::exists(temp_dir) || !filesystem::is_directory(temp_dir)) {
        cerr << "Temp directory does not exist or is not a directory." << endl;
        exit(EXIT_FAILURE);
    }

    for (const auto& entry : filesystem::directory_iterator(temp_dir)) {
        if (filesystem::is_regular_file(entry)) {
            filesystem::path target_path = program_dir / entry.path().filename();
            if(filesystem::exists(target_path)){
                filesystem::remove(target_path);
            }
            filesystem::copy(entry, target_path, filesystem::copy_options::overwrite_existing);
        }
    }
}
void RequireArg(string opt,int num,int of,bool overwar=0){
    if(of==num) return ;
    if(of>num){
        if(overwar){
            cerr<<format("At line {}:\n---- warring: too many arguments to function '{}'.\n",lineid,opt);
            cerr<<format("---- '{}' requires {} argument{}, but there {} {}...... ignoring from {}!\n",opt,num,num<=1?"":"",of==1?"is":"are",of,num+1);
        }
        return ;
    }
    cerr<<format("At line {}:\n---- error: too few arguments to function '{}'.\n",lineid,opt);
    cerr<<format("---- '{}' requires {} argument{}, but there {} only {}.\n",opt,num,num<=1?"":"",of==1?"is":"are",of);
    deletefile();
    exit(EXIT_FAILURE);
}
void isValidNumber(const string& opt,const string& s) {
    try{
        size_t pos;
        if(fabs(stod(s, &pos))>999999984306749440.000000) throw out_of_range("Value is out of range!");
        if(pos!=s.size()){
            cerr<<format("At line {}:\n---- error: function '{}' requires a number argument, but '{}' is provided.\n",lineid,opt,s);
            deletefile();
            exit(EXIT_FAILURE);
        }
        return ;
    }catch(invalid_argument) {
        cerr<<format("At line {}:\n---- error: function '{}' requires a number argument, but '{}' is provided.\n",lineid,opt,s);
        deletefile();
        exit(EXIT_FAILURE);
    }catch(out_of_range) {
        cerr<<format("At line {}:\n---- error: argument {} overflowed. it shouldn't be bigger than 999999984306749440.000000\n",lineid,s);
        deletefile();
        exit(EXIT_FAILURE);
    }
}
string ensure_extension(const string& filename){
    filesystem::path file_path(filename);
    if(file_path.extension().empty()) {
        return filename+".cs2script";
    }
    return filename;
}
void genInit(){
    fout=ofstream("Temp/run.cfg",ios::out);
    fout<<"//[Gen]";
    fout<<R"(
+syncer_nomsg
syncer_fetch;hzScheduler_begintime =;syncer_curtime | toggle hzScheduler_begintime
)";
fout<<format("exec {}/0",path);
}
int main(int argc, char* argv[]) {
    deletefile();
    if(!tempdir.empty() && !filesystem::exists(tempdir)) {
        filesystem::create_directories(tempdir);
    }

    vector<string> argls(argv, argv + argc);

    if(argls.size()!=2){
        cerr<<"Error: Invalid number of arguments.\n";
        cerr<<"Usage: scfg <input file>\n";
        cerr<<"Example: scfg input.cs2script\n";
        exit(EXIT_FAILURE);
    }

    argls[1]=ensure_extension(argls[1]);

    fin=ifstream(argls[1],ios::in);
    if(!fin){
        cerr<<format("file {} does not exists.\n",argls[1]);
        exit(EXIT_FAILURE);
    }
    
    keyword.insert("SRC");
    keyword.insert("SLEEP");
    keyword.insert("SETANG");
    keyword.insert("ANG");
    keyword.insert("MOVEANG");
    keyword.insert("PLAY");
    keyword.insert("BEEP");
    keyword.insert("CVAR");
    keyword.insert("LOCKMOUSE");
    keyword.insert("UNLOCKMOUSE");
    keyword.insert("END");
    keyword.insert("SETBEGIN");
    keyword.insert("DEFINEPATH");
    keyword.insert("CHECKTIME");

    for(auto& s:keyword){
        keywordbylen[s.size()].insert(s);
    }

    bool use_ANG_after_MOVEANG = 0;
    int pathinit = 0;

    for(lineid=1;;lineid++){
        auto lineargs=readargs();
        if(lineargs.size()==0){
            cerr<<format("At line {}:\n---- error: Missing 'END' flag in the end of file.\n",lineid);
            deletefile();
            exit(EXIT_FAILURE);
        }
        auto opt=lineargs[0];
        lineargs=popfront(lineargs);

        if(keyword.find(opt)==keyword.end()){
            if(opt.length()>=2 && opt.substr(0,2)=="//")    continue;
            cerr<<format("At line {}:\n---- error: Command {} Not Found.\n",lineid,opt);
            for(int i=1;i<=opt.size() && i<=keywordmaxlen;i++){
                string trys=toUpper(opt.substr(0,i));
                auto it=keywordbylen[i].find(trys);
                if(it==keywordbylen[i].end())   continue;
                cerr<<format("---- did you mean '{}'?",trys);
            }
            exit(EXIT_FAILURE);
        }

        if(opt=="DEFINEPATH"){
            if(pathinit){
                cerr<<format("At line {}:\n---- error: Path has already been defined at line {}.\n",lineid,pathinit);
                deletefile();
                exit(EXIT_FAILURE);
            }
            pathinit=lineid;
            RequireArg(opt,1,lineargs.size(),1);
            path=lineargs[0];

            genInit();

            fout=ofstream("Temp/0.cfg",ios::out);
            fout<<"//[Gen]\n\n";
            slp(CVARSLEEP);
            continue;
        }
        if(!pathinit){
            cerr<<format("At line {}:\n---- error: Path hasn't been defined in script.\n",lineid);
            deletefile();
            exit(EXIT_FAILURE);
        }
        if(opt=="SRC"){
            RequireArg(opt,1,lineargs.size(),0);
            src(UnionWithSpace(lineargs));
        }else if(opt=="SLEEP"){
            RequireArg(opt,1,lineargs.size(),1);
            isValidNumber(opt,lineargs[0]);
            double slptime=stod(lineargs[0]);
            if(slptime>3600){
                cerr<<format("At line {}:\n---- warring: 'SLEEP {}' will pause over 1 hour. Are you sure?\n",lineid,slptime);
            }
            slp(slptime,0);
        }else if(opt=="SETANG"){
            use_ANG_after_MOVEANG=0;
            RequireArg(opt,7,lineargs.size(),1);
            setang(stod(lineargs[5]),stod(lineargs[4]));
        }else if(opt=="ANG"){
            if(use_ANG_after_MOVEANG){
                cerr<<format("At line {}:\n---- warring: You are using 'ANG' after 'MOVEANG', which is inaccurate. Are you sure?\n",lineid);
                cerr<<format("---- Suggest using 'SETANG' at least once between 'MOVEANG' and 'ANG'\n",lineid);
                use_ANG_after_MOVEANG=0;
            }
            RequireArg(opt,7,lineargs.size(),1);
            ang(stod(lineargs[5]),stod(lineargs[4]));
        }else if(opt=="MOVEANG"){
            use_ANG_after_MOVEANG=1;
            RequireArg(opt,7,lineargs.size(),1);
            turntoang(stod(lineargs[5]),stod(lineargs[4]));
        }else if(opt=="PLAY"){
            RequireArg(opt,1,lineargs.size(),0);
            play(UnionWithSpace(lineargs));
        }else if(opt=="BEEP"){
            RequireArg(opt,0,lineargs.size(),1);
            play("sounds/tools/sfm/beep.vsnd_c");
        }else if(opt=="CVAR"){
            RequireArg(opt,2,lineargs.size(),0);
            cvar(lineargs[0],UnionWithSpace(popfront(lineargs)));
        }else if(opt=="LOCKMOUSE"){
            RequireArg(opt,0,lineargs.size(),1);
            src("hzScheduler_mouse_lock");  
        }else if(opt=="UNLOCKMOUSE"){
            RequireArg(opt,0,lineargs.size(),1);
            src("hzScheduler_mouse_pass");  
        }else if(opt=="SETBEGIN"){
            tottime=0;
            RequireArg(opt,0,lineargs.size(),1);
            src("syncer_fetch;hzScheduler_begintime =;syncer_curtime | toggle hzScheduler_begintime");
        }else if(opt=="CHECKTIME"){
            RequireArg(opt,0,lineargs.size(),1);
            checktime();
        }else if(opt=="END"){
            RequireArg(opt,0,lineargs.size(),1);
            fout<<"-syncer_nomsg_later"<<endl;
            fout.close();
            cerr<<format("OK generate {} file{} successfully",N,N==1?"":"s")<<endl;
            copyfile();
            deletefile();
            exit(EXIT_SUCCESS);
        }
    }
    exit(EXIT_SUCCESS);
}