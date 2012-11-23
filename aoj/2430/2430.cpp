#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;
#define INF (1<<28)

int n, a[4096];
int dp[4096][4096], fr[4096][4096];
Int s[4096];

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", a+i);
    rep (i, n) s[i+1] = s[i] + a[i];
    rep (i, n) dp[0][i+1] = 1;
    rep (i, n) {
        vector<pair<Int, int> > v;
        rep (j, i) if (dp[j][i]) v.push_back(mp(s[i]-s[j], j));
        for (int j = i+1; j <= n; j++) v.push_back(mp(s[j]-s[i], -j));
        sort(v.begin(), v.end());
        int mx = 0, mi = -1;
        rep (k, v.size()) {
            const int j = v[k].second;
            if (j < 0) {
                if (mi != -1) {
                    dp[i][-j] = mx + 1;
                    fr[i][-j] = mi;
                }
            }
            else {
                if (mx < dp[j][i]) {
                    mx = dp[j][i];
                    mi = j;
                }
            }
        }
    }
    int ans = -1, pre = -1;
    rep (i, n) {
        if (ans < dp[i][n]) {
            ans = dp[i][n];
            pre = i;
        }
    }
    printf("%d\n", ans);
    vector<int> ax;
    int cur = n;
    while (pre != 0) {
        ax.push_back(pre);
        const int npre = fr[pre][cur];
        cur = pre;
        pre = npre;
    }
    rep (i, ax.size()) {
        if (i) putchar(' ');
        printf("%d", ax[ax.size()-1-i]);
    }
    printf("\n");
    return 0;
}
