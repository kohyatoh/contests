#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int mem[32768];

void run(const string cmd, const vector<int>& cs) {
    memset(mem, 0, sizeof(mem));
    int p = 0;
    for(int i=0; i<(int)cmd.size(); i++) {
        switch(cmd[i]) {
            case '>':
                p = (p+1)%32768;
                break;
            case '<':
                p = (p+32767)%32768;
                break;
            case '+':
                mem[p] = (mem[p]+1)%256;
                break;
            case '-':
                mem[p] = (mem[p]+255)%256;
                break;
            case '.':
                putchar(mem[p]);
                break;
            case '[':
                if(mem[p]==0) i = cs[i];
                break;
            case ']':
                if(mem[p]!=0) i = cs[i];
                break;
        }
    }
}

int main() {
    string s;
    getline(cin, s);
    const int T = atoi(s.c_str());
    rep(_q, T) {
        printf("PROGRAM #%d:\n", _q+1);
        string cmd;
        vector<int> cs, stk;
        bool err = false;
        for(;;) {
            getline(cin, s);
            if(s=="end") break;
            rep(i, s.size()) {
                if(s[i]=='%') break;
                switch(s[i]) {
                case '>':
                case '<':
                case '+':
                case '-':
                case '.':
                    cmd += s[i];
                    cs.push_back(0);
                    break;
                case '[':
                    cmd += s[i];
                    stk.push_back(cs.size());
                    cs.push_back(0);
                    break;
                case ']':
                    cmd += s[i];
                    if(stk.size()==0) err = true;
                    else {
                        const int ix = stk.back();
                        stk.pop_back();
                        cs[ix] = cs.size();
                        cs.push_back(ix);
                    }
                    break;
                }
            }
        }
        if(stk.size()) err = true;
        if(err) puts("COMPILE ERROR");
        else {
            run(cmd, cs);
            putchar('\n');
        }
    }
    return 0;
}
