#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, x[5000], y[5000], m;
vector<int> xs, ys;
int sum[5010][5010];

int of(const vector<int>& xs, int x) {
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
}

int solve(int x1, int y1, int x2, int y2) {
    if (x1 > xs.back() || x2 < xs[0]) return 0;
    if (y1 > ys.back() || y2 < ys[0]) return 0;
    const int ix1 = of(xs, x1), ix2 = of(xs, x2+1);
    const int iy1 = of(ys, y1), iy2 = of(ys, y2+1);
    return sum[ix2][iy2] - sum[ix2][iy1] - sum[ix1][iy2] + sum[ix1][iy1];
}

int main() {
    scanf("%d%d", &n, &m);
    rep (i, n) scanf("%d%d", x+i, y+i);
    rep (i, n) xs.push_back(x[i]), ys.push_back(y[i]);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    rep (i, n) sum[of(xs, x[i])+1][of(ys, y[i])+1]++;
    rep (i, xs.size()+1) rep (j, ys.size()+1) {
        if (i) sum[i][j] += sum[i-1][j];
        if (j) sum[i][j] += sum[i][j-1];
        if (i && j) sum[i][j] -= sum[i-1][j-1];
    }
    rep (_, m) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", solve(x1, y1, x2, y2));
    }
    return 0;
}
