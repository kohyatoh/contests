#include <stdio.h>
#include <string.h>
#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1LL<<60)
typedef long long Int;
inline void cmin(Int &a, Int b) { if (a > b) a = b; }

int n, a[1024], to[1024], col[1024], sum[1024], cnt[1024], mun[1024];

int main() {
    for (int _q = 0;; _q++) {
        scanf("%d", &n);
        if (n == 0) return 0;
        rep (i, n) scanf("%d", a+i);
        rep (i, n) to[a[i]] = i;
        sort(a, a+n);
        memset(col, -1, sizeof(col));
        int m = 0;
        rep (i, n) if (col[i] == -1) {
            int t = i;
            sum[m] = 0;
            cnt[m] = 0;
            mun[m] = 10000;
            do {
                col[t] = m;
                cnt[m]++;
                sum[m] += a[t];
                mun[m] = min(mun[m], a[t]);
                t = to[a[t]];
            } while (t != i);
            m++;
        }
        int ans = 0;
        rep (i, m) {
            int add = (cnt[i]-2)*mun[i] + sum[i];
            if (mun[i] != a[0]) {
                add = min(add, a[0] + mun[i] + cnt[i]*a[0] + sum[i]);
            }
            ans += add;
        }
        printf("Case %d: %d\n\n", _q+1, ans);
    }
}
