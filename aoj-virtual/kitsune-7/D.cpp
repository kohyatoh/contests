#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef complex<int> P;

int dot(const P& a, const P& b) { return real(conj(a)*b); }
int cross(const P& a, const P& b) { return imag(conj(a)*b); }
int ccw(const P& a, P b, P c) {
    b -= a, c -= a;
    if (cross(b, c) > 0) return 1;
    if (cross(b, c) < 0) return -1;
    if (dot(b, c) < 0) return 2;
    if (norm(b) < norm(c)) return -2;
    return 0;
}
bool intersectSS(const P& s0, const P& s1, const P& t0, const P& t1) {
    return ccw(s0, s1, t0) * ccw(s0, s1, t1) <= 0
        && ccw(t0, t1, s0) * ccw(t0, t1, s1) <= 0;
}

const char dat[13] = "123456789*0#";
char buf[128];
int vis[128];
vector<P> ps;

bool conn(int i, int j) {
    return intersectSS(ps[i], ps[i+1], ps[j], ps[j+1])
        && cross(ps[i+1]-ps[i], ps[j+1]-ps[j]) == 0;
}

void rec(int at) {
    if (vis[at]) return ;
    vis[at] = 1;
    rep (i, ps.size()-1) if (conn(at, i)) rec(i);
}

int solve() {
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    rep (i, ps.size()-1) if (vis[i] == 0) {
        ans++;
        rec(i);
    }
    return ans;
}

int main() {
    map<char, P> of;
    rep (y, 4) rep (x, 3) of[dat[y*3+x]] = P(x, y);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", buf);
        ps.clear();
        for (int i = 0; buf[i]; i++) {
            assert(of.count(buf[i]));
            ps.push_back(of[buf[i]]);
        }
        ps.erase(unique(ps.begin(), ps.end()), ps.end());
        const int ans = solve();
//        printf("%d\n", ans);
        if (ans <= 3) puts("EXCELLENT");
        else if (ans == 4) puts("GOOD");
        else puts("BAD");
    }
    return 0;
}

