#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

int main() {
    map<char, Int> of;
    of['C'] = 12010;
    of['H'] =  1008;
    of['O'] = 16000;
    of['N'] = 14010;
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<string> vs;
        int pre = 0;
        rep (i, s.size()) if (i > 0) {
            if (isalpha(s[i])) {
                vs.push_back(s.substr(pre, i-pre));
                pre = i;
            }
        }
        vs.push_back(s.substr(pre));
        Int ans = 0;
        rep (i, vs.size()) {
//            cerr << vs[i] << endl;
            int num = 1;
            if (vs[i].size() > 1) num = atoi(vs[i].c_str()+1);
            ans += num * of[vs[i][0]];
        }
        printf("%d.%03d\n", (int)(ans/1000), (int)(ans%1000));
    }
    return 0;
}
