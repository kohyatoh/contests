#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define N (200000)

int n, a[N];
int le[N], ri[N], t[N];

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", a+i+1);
    a[0] = -1;
    a[n+1] = 2*n;
    rep (i, n+2) {
        le[i] = i-1;
        ri[i] = i+1;
    }
    le[0] = 0;
    ri[n+1] = n+1;
    vector<int> c;
    rep (i, n+2) if (a[i] < a[le[i]]) c.push_back(i);
    int ans = 0;
    while (!c.empty()) {
        rep (i, c.size()) t[c[i]] = 1;
        ans++;
        vector<int> m;
        rep (i, c.size()) {
            const int ix = c[i];
            ri[le[ix]] = ri[ix];
            le[ri[ix]] = le[ix];
            if (t[ri[ix]] == 0) m.push_back(ri[ix]);
            if (t[le[ix]] == 0) m.push_back(le[ix]);
        }
        sort(m.begin(), m.end());
        m.erase(unique(m.begin(), m.end()), m.end());
        c.clear();
        rep (i, m.size()) {
            const int ix = m[i];
            if (a[ix] < a[le[ix]]) c.push_back(ix);
        }
    }
    printf("%d\n", ans);
    return 0;
}
