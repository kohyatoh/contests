#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

bool startsWith(const string& a, const string& p) {
    if(a.size()<p.size()) return false;
    rep(i, p.size()) if(a[i]!=p[i]) return false;
    return true;
}

bool endsWith(const string& a, const string& p) {
    if(a.size()<p.size()) return false;
    const int b = a.size()-p.size();
    rep(i, p.size()) if(a[b+i]!=p[i]) return false;
    return true;
}

const char prefix[6][3][32] = {
    {"anti", "against ", ""},
    {"post", "after ", ""},
    {"pre", "before ", ""},
    {"re", "", " again"},
    {"un", "not ", ""},
    {"", "", ""},
};
const char suffix[6][3][32] = {
    {"er", "one who ", "s"},
    {"ing", "to actively ", ""},
    {"ize", "change into ", ""},
    {"s", "multiple instances of ", ""},
    {"tion", "the process of ", "ing"},
    {"", "", ""},
};

char buf[128];

int main() {
    vector<string> ps, ss;
    rep(i, 6) ps.push_back(prefix[i][0]);
    rep(i, 6) ss.push_back(suffix[i][0]);
    gets(buf);
    int T = atoi(buf);
    while(T--) {
        gets(buf);
        string ans(buf);
        rep(i, 6) if(startsWith(ans, ps[i])) {
            string t(ans.substr(ps[i].size()));
            rep(j, 6) if(endsWith(t, ss[j])) {
                string root(t.substr(0, t.size()-ss[j].size()));
                printf("%s%s%s%s%s\n",
                        prefix[i][1], suffix[j][1],
                        root.c_str(),
                        suffix[j][2], prefix[i][2]);
                break;
            }
            break;
        }
    }
    return 0;
}
