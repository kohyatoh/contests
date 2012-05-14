#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, a[128];

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", a+i);
    sort(a, a+n);
    reverse(a, a+n);
    int y = 0;
    rep (i, n) y += a[i];
    int m = 0;
    rep (i, n) {
        m += a[i];
        y -= a[i];
        if (m > y) {
            printf("%d\n", i+1);
            break;
        }
    }
    return 0;
}
