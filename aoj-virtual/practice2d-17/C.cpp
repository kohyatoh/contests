#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

#define NUM (120000)
int N, M, Q, Y[NUM];
vector<int> ls[NUM];
pair<int, int> ord[NUM];
int hi[NUM], p[NUM], c[NUM], f[NUM], b[NUM], ans[NUM];
vector<pair<int, int> > a[NUM];

void fix(int k) {
    sort(a[k].begin(), a[k].end());
    f[k] = a[k][0].first;
    c[k] = 0;
    rep (i, a[k].size()) c[k] += a[k][i].second == -1 ? 1 : c[a[k][i].second];
}

void build() {
    Y[M] = -1;
    rep (i, N) hi[i] = -1;
    rep (i, M+1) ord[i] = mp(Y[i], i);
    sort(ord, ord+M+1);
    for (int ik = M; ik > 0; ik--) {
        const int k = ord[ik].second;
        a[k].clear();
        p[k] = -1;
        rep (i, ls[k].size()) {
            const int ix = ls[k][i]-1;
            if (hi[ix] == -1) a[k].push_back(mp(ix, -1));
            else {
                a[k].push_back(mp(f[hi[ix]], hi[ix]));
                assert(p[hi[ix]] == -1);
                p[hi[ix]] = i;
            }
            hi[ix] = k;
        }
        fix(k);
    }
    a[M].clear();
    rep (i, N) if (hi[i] == -1) a[M].push_back(mp(i, -1));
    rep (i, M) if (p[i] == -1) a[M].push_back(mp(f[i], i));
    fix(M);
    b[M] = 0;
    rep (ik, M+1) {
        const int k = ord[ik].second;
        int z = b[k];
        rep (i, a[k].size()) {
            if (a[k][i].second == -1) {
                ans[z] = a[k][i].first;
                z++;
            }
            else {
                b[a[k][i].second] = z;
                z += c[a[k][i].second];
            }
        }
    }
}

int main() {
    for (;;) {
        scanf("%d%d%d", &N, &M, &Q);
        if (N == 0) return 0;
        rep (i, M) {
            scanf("%d", Y+i);
            int L;
            scanf("%d", &L);
            ls[i].resize(L);
            rep (j, L) scanf("%d", &ls[i][j]);
        }
        build();
        rep (i, Q) {
            int q;
            scanf("%d", &q);
            printf("%d\n", ans[q-1]+1);
        }
        printf("\n");
    }
}
