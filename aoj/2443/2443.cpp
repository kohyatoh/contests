#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

int n, a[16];

Int pack(int *a) {
    Int b = 0;
    rep (i, n) b = b*16+a[i];
    return b;
}

void unpack(Int b, int *a) {
    rep (i, n) {
        a[n-1-i] = b%16;
        b /= 16;
    }
}

int solve() {
    static int b[16];
    queue<pair<int, Int> > q;
    const Int beg = pack(a);
    rep (i, n) b[i] = i+1;
    const Int end = pack(b);
    map<Int, int> rt;
    q.push(mp(0, beg));
    rt[beg] = 0;
    while (!q.empty()) {
        pair<int, Int> vv = q.front();
        q.pop();
        unpack(vv.second, b);
        if (vv.first <= 3) rep (i, n) rep (j, i) {
            reverse(b+j, b+i+1);
            const Int p = pack(b);
            if (rt.count(p) == 0) {
                if (vv.first < 3) q.push(mp(vv.first+1, p));
                rt[p] = vv.first+1;
            }
            reverse(b+j, b+i+1);
        }
    }
    set<Int> vis;
    q.push(mp(0, end));
    while (!q.empty()) {
        pair<int, Int> vv = q.front();
        q.pop();
        if (vis.count(vv.second)) continue;
        vis.insert(vv.second);
        if (rt.count(vv.second)) return vv.first+rt[vv.second];
        unpack(vv.second, b);
        rep (i, n) rep (j, i) {
            reverse(b+j, b+i+1);
            q.push(mp(vv.first+1, pack(b)));
            reverse(b+j, b+i+1);
        }
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", a+i);
    printf("%d\n", solve());
    return 0;
}
