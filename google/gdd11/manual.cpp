#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define mp make_pair

int LX, RX, UX, DX;
int N, W[6000], H[6000];
string fields[6000], answers[6000];

void print(int w, int h, string f) {
    rep(i, h) {
        rep(j, w) cerr << f[i*w+j];
        cerr << endl;
    }
}

string toGoal(string f) {
    const int n = f.size();
    rep(i, n) if(f[i]!='=' ) {
        for(int j=i+1; j<n; j++) if(f[j]!='=') {
            if(f[i]==' ' || (f[j]!=' ' && f[i]>f[j])) swap(f[i], f[j]);
        }
    }
    return f;
}

string interactive(int w, int h, string f) {
    string b;
    char op;
    int cur = f.find(' '), next;
    for(;;) {
        cin >> op;
        switch(op) {
        case 'h':
            if(cur%w==0 || f[cur-1]=='=') break;
            b += 'L';
            next = cur-1;
            break;
        case 'l':
            if(cur%w==w-1 || f[cur+1]=='=') break;
            b += 'R';
            next = cur+1;
            break;
        case 'k':
            if(cur/w==0 || f[cur-w]=='=') break;
            b += 'U';
            next = cur-w;
            break;
        case 'j':
            if(cur/w==h-1 || f[cur+w]=='=') break;
            b += 'D';
            next = cur+w;
            break;
        case 'u':
            if(b.size()==0) break;
            switch(b[b.size()-1]) {
            case 'L': next=cur+1; break;
            case 'R': next=cur-1; break;
            case 'U': next=cur+w; break;
            case 'D': next=cur-w; break;
            }
            b.resize(b.size()-1);
            break;
        case 'q':
            return b;
        }
        swap(f[cur], f[next]);
        cur = next;
        cerr << endl;
        print(w, h, toGoal(f));
        cerr << endl;
        print(w, h, f);
        cerr << b << endl;
    }
}

int main(int argc, char *argv[]) {
    int opt;
    string preload_filename, problem_filename;
    while((opt=getopt(argc, argv, "w:f:"))!=-1) {
        switch(opt) {
        case 'w':
            preload_filename = optarg;
            break;
        case 'f':
            problem_filename = optarg;
            break;
        }
    }
    {
        fstream fin(problem_filename.c_str(), ios::in);
        fin >> LX >> RX >> UX >> DX;
        fin >> N;
        rep(i, N) {
            char _;
            fin >> W[i] >> _ >> H[i] >> _ >> fields[i];
            rep(j, fields[i].size()) if(fields[i][j]=='0') fields[i][j] = ' ';
        }
    }
    if(preload_filename.size()) {
        fstream fin(preload_filename.c_str(), ios::in);
        rep(i, N) getline(fin, answers[i]);
        fin.close();
    }
    for(;;) {
        map<int, vector<int> > m;
        rep(i, N) m[answers[i].size()].push_back(i);
        foreach(it, m) if(it->first==0 || it->first>100) {
            cerr << it->first << ": ";
            rep(i, it->second.size()) {
                cerr << ' ' << it->second[i]+1;
            }
            cerr << endl;
        }
        cerr << "What?" << endl;
        int ix;
        cin >> ix;
        if(ix<=0) break;
        ix -= 1;
        print(W[ix], H[ix], toGoal(fields[ix]));
        cerr << endl;
        print(W[ix], H[ix], fields[ix]);
        cerr << endl;
        answers[ix] = interactive(W[ix], H[ix], fields[ix]);
    }
    rep(i, N) {
        cout << answers[i] << endl;
    }
    return 0;
}

