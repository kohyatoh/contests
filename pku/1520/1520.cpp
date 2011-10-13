#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
using namespace std;
typedef long long Int;

string upper(string s) {
    rep(i, s.size()) s[i] = toupper(s[i]);
    return s;
}

int main() {
    for(;;) {
        string s;
        getline(cin, s);
        if(s==".") return 0;
        vector<string> ss;
        int h = 0;
        rep(i, s.size()) if(s[i]==',' || s[i]=='.') {
            ss.push_back(s.substr(h, i-h));
            h = i+2;
        }
        vector<int> is;
        vector<Int> as;
        vector<pair<string, string> > ts;
        rep(i, ss.size()) {
            bool isnum = true;
            rep(j, ss[i].size()) {
                if(!isdigit(ss[i][j]) && (j>0 || ss[i][j]!='-')) isnum = false;
            }
            is.push_back(isnum);
            if(isnum) as.push_back(atoll(ss[i].c_str()));
            else ts.push_back(mp(upper(ss[i]), ss[i]));
        }
        sort(as.begin(), as.end());
        sort(ts.begin(), ts.end());
        int i = 0, j = 0;
        rep(k, ss.size()) {
            if(is[k]) cout << as[i++];
            else cout << ts[j++].second;
            if(k==(int)ss.size()-1) cout << '.' << endl;
            else cout << ", ";
        }
    }
}
