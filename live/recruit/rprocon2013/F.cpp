#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

#define M (26)
int lim[3] = { 10, 9, 7 };
int m, f[32];
int g[32][32];

string draw(int at, int t) {
    if (f[at] == t) return "";
    f[at] = t;
    string a = string(1, at+'a');
    rep (i, M) if (g[at][i]) a += draw(i, t);
    return a;
}

bool can(int *c, int a2) {
    rep (i, 3) {
        if (c[i] > lim[i]) return false;
        a2 -= min(a2, (lim[i] - c[i]) / 2);
    }
    return a2 == 0;
}

string solve() {
    memset(f, -1, sizeof(f));
    vector<string> ns, ns2, ns1;
    vector<int> as;
    int m = 0, a2 = 0;
    rep (i, M) if (f[i] == -1) {
        string s = draw(i, m++);
        const int a = s.size();
//        cout << s << endl;
//        printf("%d\n", a);
        if (a > 2) as.push_back(a), ns.push_back(s);
        else if (a == 2) a2++, ns2.push_back(s);
        else ns1.push_back(s);
    }
    int PW = 1;
    rep (i, as.size()) PW = PW * 3;
    int c[3];
    rep (b, PW) {
        rep (i, 3) c[i] = 0;
        int w = b;
        rep (i, as.size()) {
            c[w%3] += as[i];
            w = w / 3;
        }
        if (can(c, a2)) {
            string ans[3];
            int w = b;
            rep (i, as.size()) {
                ans[w%3] += ns[i];
                w = w / 3;
            }
            rep (i, ns2.size()) {
                rep (j, 3) if (ans[j].size() + 2 <= lim[j]) {
                    ans[j] += ns2[i];
                    break;
                }
            }
            rep (i, ns1.size()) {
                rep (j, 3) if (ans[j].size() + 1 <= lim[j]) {
                    ans[j] += ns1[i];
                    break;
                }
            }
            return ans[0] + ' ' + ans[1] + ' ' + ans[2];
        }
    }
    return "IMPOSSIBLE";
}

int main() {
    int T;
    cin >> T;
    rep (_, T) {
        memset(g, 0, sizeof(g));
        int n;
        cin >> n;
        rep (k, n) {
            string s;
            cin >> s;
            rep (i, s.size()) rep (j, s.size()) {
                g[s[i]-'a'][s[j]-'a'] = 1;
            }
        }
        cout << solve() << endl;
    }
    return 0;
}

