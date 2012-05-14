#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

int n, of[100000], r[100000];
char buf[2000000];
pair<string, int> s[100000];
int m;
vector<int> p[1001000];
int la[1001000], last[1001000], h[1001000];

inline void init(int i) {
    p[i].clear();
    la[i] = -1;
    last[i] = -1;
}

void prepare() {
    sort(s, s+n);
    m = 0;
    init(m++);
    rep (k, n) {
        const char *x = s[k].first.c_str();
        int cur = 0;
        while (*x) {
            if (last[cur] == *x) {
                cur = la[cur];
            }
            else {
                init(m);
                last[cur] = *x;
                la[cur] = m;
                p[m].push_back(cur);
                cur = m++;
            }
            x++;
        }
        of[s[k].second] = cur;
    }
    rep (i, m) if (i != 0) {
        const int pre = p[i][0];
        h[i] = h[pre] + 1;
        for (int k = 1, x = 2; x <= h[i]; k++, x*=2) {
            p[i].push_back(p[p[i][k-1]][k-1]);
        }
    }
}

int get(int x, int h) {
    while (h) {
        int k = 0, z = 1;
        while (z*2 <= h) k++, z*=2;
        h -= z;
        x = p[x][k];
    }
    return x;
}

int solve(int ix, int jx) {
    const int x = of[ix], y = of[jx];
    int l = 0, r = min(h[x], h[y])+1;
    while (r-l>1) {
        const int mid = (l+r)/2;
        if (get(x, h[x]-mid) == get(y, h[y]-mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        scanf("%d", &n);
        rep (i, n) {
            scanf(" %s", buf);
            s[i].first = buf;
            s[i].second = i;
        }
        prepare();
        printf("Case %d:\n", _q+1);
        int Q;
        scanf("%d", &Q);
        while (Q--) {
            int i, j;
            scanf("%d%d", &i, &j);
            i--, j--;
            printf("%d\n", solve(i, j));
        }
    }
    return 0;
}
