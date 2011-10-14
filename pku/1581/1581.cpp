#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define pb push_back

int main() {
    int n;
    cin >> n;
    vector<string> name;
    vector<int> c, t;
    rep(i, n) {
        int cc=0, ct=0;
        string s;
        cin >> s;
        rep(_, 4) {
            int sub, time;
            cin >> sub >> time;
            if(time) cc++, ct+=(sub-1)*20+time;
        }
        name.pb(s);
        c.pb(cc);
        t.pb(ct);
    }
    pair<int, int> ans(-1, 0);
    rep(i, n) ans = max(ans, mp(c[i], -t[i]));
    rep(i, n) if(mp(c[i], -t[i])==ans) {
        printf("%s %d %d\n", name[i].c_str(), c[i], t[i]);
    }
    return 0;
}
