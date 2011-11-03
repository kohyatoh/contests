#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

vector<string> split(const string& s) {
    vector<string> as;
    int pre = 0;
    rep(i, s.size()) if(s[i]==' ') {
        as.push_back(s.substr(pre, i-pre));
        pre = i+1;
        if(as.size()==3) break;
    }
    as.push_back(s.substr(pre));
    return as;
}

int main() {
    vector<string> rs;
    for(;;) {
        string s;
        getline(cin, s);
        vector<string> vs(split(s));
        const double A = atof(vs[0].c_str());
        const double R = atof(vs[2].c_str());
        const double t = A/R;
        if(A<0) break;
        if(t<0.01) rs.push_back(vs[3]);
        else {
            printf("%s %.1f %s %.0f%%\n",
                    vs[3].c_str(), A, vs[1].c_str(), t*100);
        }
    }
    puts("Provides no significant amount of:");
    rep(i, rs.size()) puts(rs[i].c_str());
    return 0;
}
