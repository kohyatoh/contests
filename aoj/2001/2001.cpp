#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int xs[128];
pair<int, pair<int, int> > bs[1024];

int main() {
    for (;;) {
        int n, m, a;
        scanf("%d%d%d", &n, &m, &a);
        if (n == 0 && m == 0 && a == 0) return 0;
        a--;
        rep (i, m) {
            int h, p, q;
            scanf("%d%d%d", &h, &p, &q);
            p--, q--;
            bs[i] = mp(h, mp(p, q));
        }
        sort(bs, bs+m);
        rep (i, n) xs[i] = i;
        rep (i, m) swap(xs[bs[i].second.first], xs[bs[i].second.second]);
        printf("%d\n", xs[a]+1);
    }
}
