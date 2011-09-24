#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
typedef long long Int;

int n, m, p[30];

vector<string> split(const string& s, char sep) {
    vector<string> v;
    int pre = 0;
    rep(i, s.size()) if(s[i]==sep) {
        v.push_back(s.substr(pre, i-pre));
        pre = i+1;
    }
    v.push_back(s.substr(pre));
    return v;
}

int u[256];

int main() {
    for(;;) {
        string ex;
        getline(cin, ex);
        if(ex[0]=='#') return 0;
        vector<string> cls(split(ex, '|'));
        bool ans = false;
        rep(i, cls.size()) {
            const string s(cls[i].substr(1, cls[i].size()-2));
            vector<string> lits(split(s, '&'));
            memset(u, 0, sizeof(u));
            bool can = true;
            rep(i, lits.size()) {
                if(lits[i].size()==1) {
                    const int x = lits[i][0];
                    if(u[x]==-1) can=false;
                    u[x] = 1;
                }
                else {
                    const int x = lits[i][1];
                    if(u[x]==1) can=false;
                    u[x] = -1;
                }
            }
            if(can) {
                ans = true;
                break;
            }
        }
        puts(ans ? "yes" : "no");
    }
}
