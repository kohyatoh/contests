#include <stdio.h>
#include <string.h>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;
#define MOD (100000)

int dp[2][1<<20];

int main() {
    int n, m;
    char f[20][20];
    scanf("%d%d", &m, &n);
    rep (i, m) rep (j, n) scanf(" %c", f[i]+j);
    int *cur = dp[0], *nxt = dp[1];
    cur[0] = 1;
    const int nn = 1<<n, mask = nn-1, mm = mask-1;
    rep (h, m) {
        rep (i, n) {
            rep (b, nn) if (cur[b]) {
                const int bb = b&mm;
                const int o = i && (b&1);
                // J
                if (f[h][i] == 'J' || f[h][i] == '?') {
                    nxt[((bb<<1)&mask)|1] += cur[b];
                    nxt[((bb<<1)&mask)|1] %= MOD;
                }
                // O
                if (f[h][i] == 'O' || f[h][i] == '?') {
                    if (o) {
                        nxt[((bb<<1)&mask)|2] += cur[b];
                        nxt[((bb<<1)&mask)|2] %= MOD;
                    }
                    else {
                        nxt[((bb<<1)&mask)] += cur[b];
                        nxt[((bb<<1)&mask)] %= MOD;
                    }
                }
                // I
                if (f[h][i] == 'I' || f[h][i] == '?') {
                    if ((bb&(1<<(n-1)))==0) {
                        nxt[((bb<<1)&mask)] += cur[b];
                        nxt[((bb<<1)&mask)] %= MOD;
                    }
                }
                cur[b] = 0;
            }
            swap(cur, nxt);
        }
    }
    int ans = 1;
    rep (i, m) rep (j, n) if (f[i][j] == '?') ans = (ans*3)%MOD;
    rep (i, nn) {
        ans = (ans-cur[i]+MOD)%MOD;
    }
    printf("%d\n", ans);
    return 0;
}

