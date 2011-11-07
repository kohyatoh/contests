#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<16)

int n, a[100], mn[64][64], mx[64][64];
char ty[100];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf(" %c%d", ty+i, a+i);
    int ansv = -1;
    vector<int> ans;
    rep(k, n) {
        rep(i, n) rep(j, n) mn[i][j] = INF;
        rep(i, n) rep(j, n) mx[i][j] = -INF;
        rep(i, n) mn[i][i] = mx[i][i] = a[(i+k)%n];
        for(int w=1; w<n; w++) rep(i, n-w) {
            const int j = i+w;
            for(int p=i+1; p<=j; p++) {
                int a, b;
                if(ty[(k+p)%n]=='t') {
                    a = mn[i][p-1]+mn[p][j];
                    b = mx[i][p-1]+mx[p][j];
                }
                else {
                    a = min(min(mn[i][p-1]*mn[p][j], mn[i][p-1]*mx[p][j]),
                            min(mx[i][p-1]*mn[p][j], mx[i][p-1]*mx[p][j]));
                    b = max(max(mn[i][p-1]*mn[p][j], mn[i][p-1]*mx[p][j]),
                            max(mx[i][p-1]*mn[p][j], mx[i][p-1]*mx[p][j]));
                }
                mn[i][j] = min(mn[i][j], a);
                mx[i][j] = max(mx[i][j], b);
            }
        }
        if(ansv<mx[0][n-1]) {
            ansv = mx[0][n-1];
            ans.clear();
        }
        if(ansv == mx[0][n-1]) ans.push_back(k);
    }
    printf("%d\n", ansv);
    rep(i, ans.size()) printf("%d%c", ans[i]+1, i<(int)ans.size()-1?' ':'\n');
    return 0;
}
