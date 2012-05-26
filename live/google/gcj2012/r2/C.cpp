#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

int N, to[4000];
int ans[4000];
vector<int> g[4000];

bool solve() {
    rep (i, 4000) g[i].clear();
    to[N-1] = N;
    rep (i, N-1) {
        for (int j = i+1; j < to[i]; j++) {
            if (to[j] > to[i]) return false;
        }
    }
    rep (i, N) g[to[i]].push_back(i);
    ans[N-1] = 1000000000;
    ans[N] = 1000000001;
    for (int k = N-1; k >= 0; k--) {
        double a = (double)(ans[to[k]]-ans[k])/(to[k]-k);
        rep (i, g[k].size()) {
            const int f = g[k][i];
            ans[f] = floor(ans[k]+a*(f-k)-1);
            a = (double)(ans[f]-ans[k])/(f-k);
        }
    }
    return true;
}

bool check() {
    rep (i, N-1) {
        for (int j = i+1; j < N; j++) if (j != to[i]) {
            const double a = (double)(ans[to[i]]-ans[i])/(to[i]-i);
            const double b = (double)(ans[j]-ans[i])/(j-i);
            if (a <= b) return false;
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        scanf("%d", &N);
        rep (i, N-1) scanf("%d", to+i);
        rep (i, N-1) to[i]--;
        if (solve()) {
            printf("Case #%d:", _q+1);
            rep (i, N) printf(" %d", ans[i]);
            printf("\n");
//            puts(check() ? "ok" : "Wa\n");
        }
        else {
            printf("Case #%d: Impossible\n", _q+1);
        }
    }
    return 0;
}
