#include <string.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
inline void cmin(string &a, const string& b) { if (a > b) a = b; }
inline void cmin(string &a, const string& b, const string& c) {
    if (!a.size() || (b.size()&&b[0]=='|') || (c.size()&&c[0]=='|')) return ;
    if (a.size() != b.size() + c.size()) { a = b+c; return ; }
    const int L = b.size();
    int y = strncmp(b.c_str(), a.c_str(), L);
    if (y == 0) y = strncmp(c.c_str(), a.c_str()+L, c.size());
    if (y >= 0) return ;
    rep (i, b.size()) a[i] = b[i];
    rep (i, c.size()) a[b.size()+i] = c[i];
}
 
int n, L;
char from[64];
string to[64], dp[32][24], sub[2][24];
 
string solve() {
    rep (i, 32) rep (j, 24) dp[i][j] = '|';
    bool up;
    rep (LL, L+1) do {
        up = false;
        rep (k, n) {
            int cur = 0, nxt = 1;
            rep (i, 24) sub[cur][i] = '|';
            sub[cur][0] = "";
            rep (i, to[k].size()) {
                rep (j, 24) sub[nxt][j] = '|';
                if (islower(to[k][i])) {
                    rep (x, LL) cmin(sub[nxt][x+1], sub[cur][x]+to[k][i]);
                }
                else {
                    const int t = to[k][i] - 'A';
                    rep (j, LL+1) rep (x, LL-j+1) {
                        cmin(sub[nxt][x+j], sub[cur][x], dp[t][j]);
                    }
                }
                swap(cur, nxt);
            }
            const int f = from[k] - 'A';
            if (dp[f][LL] > sub[cur][LL]) dp[f][LL] = sub[cur][LL], up = true;
        }
    } while (up);
    if (dp['S'-'A'][L] == "|") return "-";
    return dp['S'-'A'][L];
}

int main() {
    for (;;) {
        cin >> n >> L;
        if (n == 0) return 0;
        string buf;
        rep (i, n) {
            cin >> buf;
            from[i] = buf[0];
            to[i] = buf.substr(2);
        }
        cout << solve() << endl;
    }
}
