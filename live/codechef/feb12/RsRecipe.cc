#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define fst first
#define snd second
typedef long long Int;

vector<pair<int, Int> > vs[80000];
Int sum[80000], a[80000];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    rep (i, M) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        x--;
        vs[x].push_back(mp(y, z));
    }
    rep (k, N) if (vs[k].size()) {
        sort(vs[k].begin(), vs[k].end());
        int y = vs[k][0].fst;
        Int s = vs[k][0].snd;
        for (int i = 1; i < (int)vs[k].size(); i++) {
            const int ny = vs[k][i].fst;
            const Int nz = vs[k][i].snd - s;
            if (ny != y) vs[y].push_back(mp(ny, nz));
            else if (nz != 0) {
                printf("%d\n", -1);
                return 0;
            }
            y = ny;
            s += nz;
        }
        vs[k].resize(1);
    }
    for (int k = N-1; k >= 0; k--) {
        if (vs[k].size()) {
            const int y = vs[k][0].fst;
            const Int z = vs[k][0].snd;
            const Int r = sum[k+1] - sum[y];
            a[k] = z - r;
        }
        sum[k] = sum[k+1] + a[k];
    }
    rep (k, N) {
        if (k) cout << ' ';
        cout << a[k];
    }
    cout << endl;
    return 0;
}
