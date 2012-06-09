#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

const char sf[9] = "oieastbg";
const char st[9] = "01345789";

int toi(char c) {
    if ('a' <= c && c <= 'z') return 10 + c - 'a';
    return c - '0';
}

map<char, char> tbl;
int has[40][40], in[40], out[40];
int k;
string s;

int main() {
    rep (i, 8) tbl[sf[i]] = st[i];
    int T;
    cin >> T;
    rep (_q, T) {
        memset(has, 0, sizeof(has));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        cin >> k >> s;
        rep (i, s.size()-1) {
            has[toi(s[i])][toi(s[i+1])]++;
            if (tbl.count(s[i])) {
                has[toi(tbl[s[i]])][toi(s[i+1])]++;
            }
            if (tbl.count(s[i+1])) {
                has[toi(s[i])][toi(tbl[s[i+1]])]++;
            }
            if (tbl.count(s[i]) && tbl.count(s[i+1])) {
                has[toi(tbl[s[i]])][toi(tbl[s[i+1]])]++;
            }
        }
        int ss = 0;
        rep (i, 40) rep (j, 40) if (has[i][j]) {
            ss += 2;
            in[i]++, out[j]++;
        }
        int ans = ss;
        rep (i, 40) rep (j, 40) if (in[i] && out[j]) {
            in[i]--, out[j]--;
            int t = ss;
            rep (k, 40) {
                t -= min(in[k], out[k]);
            }
            ans = min(ans, t);
            in[i]++, out[j]++;
        }
        cout << "Case #" << _q+1 << ": " << ans << endl;
    }
    return 0;
}
