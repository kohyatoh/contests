#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

map<char, int> type;

bool solve(string s) {
    vector<int> v;
    rep(i, s.size()) v.push_back(type[s[i]]);
    bool any = false;
    rep(i, v.size()) if(v[i]==1) any = true;
    if(!any) return false;
    rep(i, v.size()-2) {
        const int k = v[i]+v[i+1]+v[i+2];
        if(k==0 || k==3) return false;
    }
    rep(i, s.size()-1) if(s[i]!='e' && s[i]!='o' && s[i]==s[i+1]) return false;
    return true;
}

int main() {
    type['a'] = type['e'] = type['i'] = type['o'] = type['u'] = 1;
    for(;;) {
        string s;
        getline(cin, s);
        if(s=="end") return 0;
        printf("<%s> %s acceptable.\n", s.c_str(), solve(s) ? "is" : "is not");
    }
}
