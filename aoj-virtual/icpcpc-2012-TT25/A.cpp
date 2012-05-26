#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int pt[4000];

int main() {
    pt[0] = pt[1] = -1;
    for (int i = 2; i < 4000; i++) if (pt[i] == 0) {
        for (int j = i+i; j < 4000; j+=i) pt[j] = i;
    }
    int T;
    cin >> T;
    rep (_q, T) {
        string s, ans;
        cin >> s;
        map<char, int> cnt;
        rep (i, s.size()) cnt[s[i]]++;
        for (map<char, int>::iterator it = cnt.begin();
                it != cnt.end(); ++it) {
            if (pt[it->second] == 0) ans += it->first;
        }
        if (ans.size() == 0) ans = "empty";
        printf("Case %d: %s\n", _q+1, ans.c_str());
    }
    return 0;
}
