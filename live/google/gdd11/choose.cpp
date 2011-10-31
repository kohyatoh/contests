#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define NUM (6000)
int N;
string a[NUM], b[NUM];
extern char *optarg;
extern int optind, opterr;

int main(int argc, char *argv[]) {
    int opt;
    string af, bf;
    while((opt=getopt(argc, argv, "n:a:b:"))!=-1) {
        switch(opt) {
        case 'n':
            N = atoi(optarg);
            break;
        case 'a':
            af = optarg;
            break;
        case 'b':
            bf = optarg;
            break;
        }
    }
    if(af.size()) {
        fstream fin(af.c_str(), ios::in);
        rep(i, N) getline(fin, a[i]);
        fin.close();
    }
    if(bf.size()) {
        fstream fin(bf.c_str(), ios::in);
        rep(i, N) getline(fin, b[i]);
        fin.close();
    }
    rep(i, N) {
        if(a[i].size() && b[i].size()) {
            cout << (a[i].size()<b[i].size() ? a[i] : b[i]) << endl;
        }
        else {
            cout << (a[i].size() ? a[i] : b[i]) << endl;
        }
    }
    return 0;
}

