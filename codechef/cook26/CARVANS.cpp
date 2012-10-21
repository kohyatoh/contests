#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1<<28)

int n, a[20000];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        rep (i, n) scanf("%d", a+i);
        int ans = 0, cur = a[0];
        rep (i, n) {
            if (a[i] <= cur) ans++;
            cur = min(cur, a[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
