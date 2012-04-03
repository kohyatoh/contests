#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;
#define INF (2000000000LL)

int N, M, K, C[64];
Int dp[64][16], tbl[16][16], cam[16];

int F(int a) {
    int c = 0;
    for (int p = a; p; p /= 10) if (p%10==4 || p%10==7) c++;
    return c;
}

int num(int x, int a) {
    int n = 0, ds[16];
    for (int p = a; p; p /= 10) ds[n++] = p%10;
    int c = 0;
    Int ans = 0;
    rep (i, n) {
        const int dig = ds[n-1-i];
        rep (j, dig) {
            const int h = c + (j==4 || j==7);
            if (x>=h) ans += tbl[n-1-i][x-h];
            if (ans > INF) ans = INF;
        }
        if (dig == 4 || dig == 7) c++;
    }
    // remove 0
    if (x == 0 && a) ans--;
    return ans;
}

Int f(int i, int pre, int z) {
    Int c = 0;
    rep (x, 16) {
        if (i && C[i-1]!=(x==pre)) continue;
        c += num(x, z) * dp[i][x];
        if (c > INF) c = INF;
    }
    return c;
}

int main() {
    rep (i, 16) rep (j, i+1) {
        // iCj * 2^j * 8^(i-j)
        tbl[i][j] = 1;
        rep (k, j) tbl[i][j] = tbl[i][j]*(i-k)/(k+1);
        rep (_, j) tbl[i][j] *= 2;
        rep (_, i-j) tbl[i][j] *= 8;
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &N, &M, &K);
        rep (i, N-1) scanf("%d", C+i);
        rep (i, 16) cam[i] = num(i, M+1);
        memset(dp, 0, sizeof(dp));
        rep (i, 16) dp[N-1][i] = 1;
        for (int k = N-2; k >= 0; k--) rep (i, 16) {
            rep (x, 16) {
                Int a = dp[k+1][x] * cam[x];
                if (a > INF) a = INF;
                if (C[k] == (i==x)) dp[k][i] += a;
            }
            if (dp[k][i] > INF) dp[k][i] = INF;
        }
        if (f(0, -1, M+1) < K) printf("%d\n", -1);
        else {
            int pre = -1;
            Int nth = K;
            rep (i, N) {
                int l = 1, r = M+1;
                while (r-l > 1) {
                    const int mid = (l+r) / 2;
                    if (f(i, pre, mid) < nth) l = mid;
                    else r = mid;
                }
                nth -= f(i, pre, l);
                pre = F(l);
                printf("%d%c", l, "\n "[i<N-1]);
            }
        }
    }
    return 0;
}
