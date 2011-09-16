#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, d[10000], c[10000], a[2][10000];
pair<pair<int, int>, int> v[2][10000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        memset(a, 0, sizeof(a));
        rep(i, n) scanf("%d%d", d+i, c+i);
        rep(i, n) {
            v[0][i] = mp(mp(d[i], -c[i]), i);
            v[1][i] = mp(mp(c[i], -d[i]), i);
        }
        rep(k, 2) {
            sort(v[k], v[k]+n);
            int mx = -(1<<28);
            rep(i, n) {
                const int val = v[k][i].first.second;
                a[k][v[k][i].second] = mx < val;
                mx = max(mx, val);
            }
        }
        int ans = 0;
        rep(i, n) ans += a[0][i] && a[1][i];
        printf("%d\n", ans);
    }
}
