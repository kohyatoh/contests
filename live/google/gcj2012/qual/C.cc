#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define N (3000000)
int m, of[N], cnt[N];

int main() {
    memset(of, -1, sizeof(of));
    rep (k, N) if (of[k] == -1) {
        int n = 0, a[10];
        for (int p = k; p; p /= 10) a[n++] = p%10;
        reverse(a, a+n);
        rep (i, n) if (a[i] != 0) {
            int x = 0;
            rep (j, n) x = x*10 + a[(i+j)%n];
            if (x < N) of[x] = m;
        }
        m++;
    }
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        int a, b;
        scanf("%d%d", &a, &b);
        memset(cnt, 0, sizeof(cnt));
        for (int i = a; i <= b; i++) cnt[of[i]]++;
        int ans = 0;
        rep (i, m) ans += cnt[i] * (cnt[i]-1) / 2;
        printf("Case #%d: %d\n", _q+1, ans);
    }
    return 0;
}
