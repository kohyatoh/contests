#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1<<28)

int n, x[128], y[128], vis[128];

bool reach(int at, int t) {
    if (vis[at]) return false;
    vis[at] = 1;
    if (at == t) return true;
    rep (i, n) {
        if ((x[i] < x[at] && x[at] < y[i])
            || (x[i] < y[at] && y[at] < y[i])) {
            if (reach(i, t)) return true;
        }
    }
    return false;
}

int main() {
    int q;
    scanf("%d", &q);
    rep (i, q) {
        int ty, a, b;
        scanf("%d%d%d", &ty, &a, &b);
        if (ty == 1) {
            x[n] = a;
            y[n] = b;
            n++;
        }
        else {
            a--, b--;
            memset(vis, 0, sizeof(vis));
            puts(reach(a, b) ? "YES" : "NO");
        }
    }
    return 0;
}
