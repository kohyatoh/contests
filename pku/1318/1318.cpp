#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

string sorted(string s) {
    sort(s.begin(), s.end());
    return s;
}

int main() {
    char buf[32];
    map<string, vector<string> > dict;
    for(;;) {
        scanf(" %s", buf);
        if(buf[0]=='X') break;
        const string w(buf);
        dict[sorted(w)].push_back(w);
    }
    for(map<string, vector<string> >::iterator it=dict.begin();
            it!=dict.end(); ++it) {
        sort(it->second.begin(), it->second.end());
    }
    for(;;) {
        scanf(" %s", buf);
        if(buf[0]=='X') break;
        const string w(sorted(buf));
        if(dict.count(w)) {
            const vector<string>& v = dict[w];
            rep(i, v.size()) puts(v[i].c_str());
        }
        else {
            puts("NOT A VALID WORD");
        }
        puts("******");
    }
    return 0;
}
