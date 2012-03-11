#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

int N, K, a[200000], ans[600000];
pair<int, int> bs[2][200000];

int main() {
    scanf("%d%d", &N, &K);
    rep (i, N) scanf(" %d", a+i);
    sort(a, a+N);
    int cur = 0, nxt = 1;
    int n = 0;
    bs[cur][n++] = mp(0, N);
    int y = 31;
    while (y--) {
        const int mask = 1<<y;
        Int sum = 0;
        int m = 0;
        rep (i, n) {
            const int s = bs[cur][i].first, t = bs[cur][i].second;
            int ix = s;
            while (ix < t && !(a[ix]&mask)) ix++;
            sum += (ix-s)*(ix-s-1LL)/2 + (t-ix)*(t-ix-1LL)/2;
            if (s < ix) bs[nxt][m++] = mp(s, ix);
            if (ix < t) bs[nxt][m++] = mp(ix, t);
        }
        if (sum <= K) break;
        swap(cur, nxt);
        n = m;
    }
    if (y >= 0) {
        int m = 0;
        rep (k, n) {
            const int s = bs[cur][k].first, t = bs[cur][k].second;
            for (int i = s; i < t; i++) {
                for (int j = i+1; j < t; j++) {
                    ans[m++] = a[i] ^ a[j];
                }
            }
        }
        sort(ans, ans+m);
    }
    rep (i, K) {
        printf("%d", ans[i]);
        putchar(i<K-1 ? ' ' : '\n');
    }
    return 0;
}
