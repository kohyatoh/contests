#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, a[2][128];

bool less(int n, int *a, int *b) {
    rep (i, n) if (a[i] >= b[i]) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    rep (k, 2) {
        rep (i, n) {
            char ch;
            scanf(" %c", &ch);
            a[k][i] = ch - '0';
        }
        sort(a[k], a[k]+n);
    }
    puts(less(n, a[0], a[1]) || less(n, a[1], a[0]) ? "YES" : "NO");
    return 0;
}
