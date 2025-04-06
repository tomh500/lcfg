#include "ulti.hpp"
#include <bits/stdc++.h>
using namespace std;


void loadFile(fs::path file){

}

int main(int argc,char* argv[]){
    //check argc
    if(argc<2){
        cout<<"Usage: scfg.exe <file>";
        quitf(1);
    }

    //process addtion args
    for(int i=2;i<argc;i++){

    }
    
    //get file path
    tryToAccessFile(fs::path(string(argv[1])),loadFile,{fs::path("command"),1});

    quitf(0);
}