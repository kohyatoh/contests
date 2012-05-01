#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int n, m, k, x[400], loc[400];

int main() {
    scanf("%d%d", &n, &m);
    memset(x, -1, sizeof(x));
    rep (_, m) {
        int num;
        scanf("%d", &num);
        rep (__, num) {
            int a;
            scanf("%d", &a);
            a--;
            x[a] = k;
            loc[k] = a;
            k++;
        }
    }
    int t = -1;
    rep (i, n) if (x[i] == -1) t = i;
    vector<pair<int, int> > ans;
    rep (i, k) if (x[i] != i) {
        if (x[i] != -1) {
            ans.push_back(mp(i, t));
            x[t] = x[i];
            loc[x[t]] = t;
        }
        ans.push_back(mp(loc[i], i));
        t = loc[i];
        x[t] = -1;
        x[i] = i;
        loc[x[i]] = i;
    }
    printf("%d\n", (int)ans.size());
    rep (i, ans.size()) printf("%d %d\n", ans[i].first+1, ans[i].second+1);
    return 0;
}
