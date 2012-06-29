#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

int main() {
    for (;;) {
        int n;
        scanf("%d", &n);
        if (n == 0) return 0;
        vector<vector<int> > a(n+1, vector<int>(n+1, 0));
        rep (i, n) rep (j, n) scanf("%d", &a[i][j]);
        rep (i, n) rep (j, n) a[n][i] += a[j][i];
        rep (i, n+1) rep (j, n) a[i][n] += a[i][j];
        rep (i, n+1) {
            rep (j, n+1) printf("%5d", a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
