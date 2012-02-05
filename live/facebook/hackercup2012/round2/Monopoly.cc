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
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (1<<28)
#define MOD (YOUR_MODULUS)

struct UnionSet {
    int ud[50000];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if (x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int N, D, A[50000], B[50000], R[50000];
int memo[30010][5001];

int height(int x, int d) {
    if (d < 0) return INF;
    if (x == -1) return 1;
    if (memo[x][d] != -1) return memo[x][d];
    const int ans = min(max(height(A[x], d-1), height(B[x], D)+1),
                        max(height(A[x], D)+1, height(B[x], d-1)));
    return memo[x][d] = ans;
}

int main() {
    LOG("ready");
    int T;
    scanf("%d", &T);
    rep (t, T) {
        memset(memo, -1, sizeof(memo));
        LOG("mem ready");
        scanf("%d%d", &N, &D);
        us.init();
        rep (i, N) R[i] = -1;
        rep (i, N-1) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            A[i] = R[us.root(x)];
            B[i] = R[us.root(y)];
            us.set(x, y);
            R[us.root(x)] = i;
        }
        rep (i, N-1) for (int d = 1; d <= D; d++) height(i, d);
        const int ans = height(N-2, D);
        printf("Case #%d: %d\n", t+1, ans);
    }
    return 0;
}
