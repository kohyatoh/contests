#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m, a[128];

int main() {
    scanf("%d%d", &n, &m);
    rep (i, n) a[i] = i+1;
    rep (_, m) {
        int x, y;
        scanf("%d,%d", &x, &y);
        x--, y--;
        swap(a[x], a[y]);
    }
    rep (i, n) printf("%d\n", a[i]);
    return 0;
}
