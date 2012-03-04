#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1<<30)

int n, a[40000];

int calc(int k) {
    const int m = n / k;
    if (m < 3) return -INF;
    int ans = -INF;
    rep (beg, k) {
        int s = 0;
        for (int i = beg; i < n; i += k) s += a[i];
        ans = max(ans, s);
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", a+i);
    int ans = -INF;
    for (int i = 1; i*i <= n; i++) if (n%i == 0) {
        ans = max(ans, calc(i));
        ans = max(ans, calc(n/i));
    }
    printf("%d\n", ans);
    return 0;
}
