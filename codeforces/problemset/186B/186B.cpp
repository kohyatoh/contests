#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int n, t1, t2, k;

int calc(int u, int v) {
    return u*t1*(100-k)+v*t2*100;
}

int main() {
    scanf("%d%d%d%d", &n, &t1, &t2, &k);
    vector<pair<int, int> > rs;
    rep (i, n) {
        int u, v;
        scanf("%d%d", &u, &v);
        rs.push_back(mp(-max(calc(u, v), calc(v, u)), i+1));
    }
    sort(rs.begin(), rs.end());
    rep (i, rs.size()) {
        const int p = -rs[i].first;
        printf("%d %d.%02d\n", rs[i].second, p/100, p%100);
    }
    return 0;
}
