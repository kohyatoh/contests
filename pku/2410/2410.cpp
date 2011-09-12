#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;

string enc(int n) {
    string s;
    rep(i, 8) { s += n%2+'0'; n/=2; }
    reverse(s.begin(), s.end());
    return s;
}

int dec(const string& s) {
    int n=0;
    rep(i, s.size()) { n*=2; n+=s[i]-'0'; }
    return n;
}

int accu, pc;
int mem[256];

int main() {
    for(;;) {
        string s;
        if(!(cin>>s)) return 0;
        mem[0] = dec(s);
        rep(i, 31) { cin>>s; mem[i+1]=dec(s); }
        accu = 0; pc = 0;
        for(;;) {
            int op=mem[pc]/32, x=mem[pc]%32;
            pc = (pc+1)%32;
            if(op==0) { mem[x] = accu; }
            else if(op==1) { accu = mem[x]; }
            else if(op==2) { if(accu==0) pc = x; }
            else if(op==3) {}
            else if(op==4) { accu--; if(accu<0) accu=255; }
            else if(op==5) { accu = (accu+1) % 256; }
            else if(op==6) { pc = x; }
            else { break; }
        }
        cout << enc(accu) << endl;
    }
}

