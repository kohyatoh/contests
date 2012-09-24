#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define fst first
#define snd second

bool c[64][16];
int w[64][16], num[64], pen[64];

int main() {
    for (;;) {
        int T, P, R;
        scanf("%d%d%d", &T, &P, &R);
        if (T == 0) return 0;
        memset(c, 0, sizeof(c));
        memset(w, 0, sizeof(w));
        memset(num, 0, sizeof(num));
        memset(pen, 0, sizeof(pen));
        rep (_, R) {
            int t, p, ti;
            char msg[16];
            scanf("%d%d%d%s", &t, &p, &ti, msg);
            t--, p--;
            if (msg[0] == 'C') c[t][p] = true, pen[t] += ti;
            else w[t][p]++;
        }
        rep (i, T) rep (j, P) if (c[i][j]) {
            num[i] += 1;
            pen[i] += 1200*w[i][j];
        }
        vector<pair<pair<int, int>, int> > vs;
        rep (i, T) vs.push_back(mp(mp(-num[i], pen[i]), i));
        sort(vs.begin(), vs.end());
        rep (i, T) {
            printf("%d %d %d\n", vs[i].snd+1, -vs[i].fst.fst, vs[i].fst.snd);
        }
    }
}
