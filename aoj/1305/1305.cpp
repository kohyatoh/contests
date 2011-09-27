#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
vector<string> ns[200];
map<string, int> gs;
set<string> vis;

int visit(int at) {
    if(vis.find(ns[at][0])!=vis.end()) return 0;
    vis.insert(ns[at][0]);
    int ans = 0;
    for(int i=1; i<(int)ns[at].size(); i++) {
        if(gs.find(ns[at][i])!=gs.end()) ans += visit(gs[ns[at][i]]);
        else if(vis.find(ns[at][i])==vis.end()) {
            ans += 1;
            vis.insert(ns[at][i]);
        }
    }
    return ans;
}

int main() {
    for(;;) {
        string s;
        getline(cin, s);
        n = atoi(s.c_str());
        if(n==0) return 0;
        gs.clear();
        vis.clear();
        rep(k, n) {
            getline(cin, s);
            ns[k].clear();
            int pre = 0;
            rep(i, s.size()) if(s[i]==':' || s[i]==',' || s[i]=='.') {
                ns[k].push_back(s.substr(pre, i-pre));
                pre = i+1;
            }
            gs[ns[k][0]] = k;
        }
        printf("%d\n", visit(0));
    }
}
