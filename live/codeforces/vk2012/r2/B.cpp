#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (1000000007)
inline void add(int &a, Int b) { a = (a+b) % MOD; }

int N, K, H;
struct lem {
    int m, v, i;
} ls[200000];
bool operator<(const lem& l, const lem& r) {
    if (l.m != r.m) return l.m < r.m;
    if (l.v != r.v) return l.v < r.v;
    return l.i < r.i;
}

bool solve(double t, bool out) {
    int ix = 0;
    rep (i, K) {
        while (ix < N && (i+1.0)*H/ls[ix].v > t) ix++;
        if (ix == N) return false;
        if (out) printf("%d%c", ls[ix].i, "\n "[i<K-1]);
        ix++;
    }
    return true;
}

int main() {
    scanf("%d%d%d", &N, &K, &H);
    rep (i, N) scanf("%d", &ls[i].m);
    rep (i, N) scanf("%d", &ls[i].v);
    rep (i, N) ls[i].i = i+1;
    sort(ls, ls+N);
    double r = 1e5;
    rep (i, N) r = max(r, 1.0*K*H/ls[i].v + 1e5);
    double l = 0;
    rep (_, 100) {
        const double mid = (l+r) / 2;
        if (solve(mid, false)) r = mid;
        else l = mid;
    }
    LOG(r);
    solve(r, true);
    return 0;
}

