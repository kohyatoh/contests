#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

vector<pair<int, int> > ps;
set<pair<int, int> > vis;

void rec(const pair<int, int>& p) {
    if (vis.count(p)) return ;
    vis.insert(p);
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            const pair<int, int> np(p.first+dx, p.second+dy);
            if (binary_search(ps.begin(), ps.end(), np)) rec(np);
        }
    }
}

int main() {
    int N;
    double R;
    scanf("%d%lf", &N, &R);
    R *= 1.05;
    rep (i, N) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        x += 1e7, y += 1e7;
        ps.push_back(mp(int(x/R), int(y/R)));
    }
    sort(ps.begin(), ps.end());
    int ans = 0;
    rep (i, ps.size()) if (!vis.count(ps[i])) rec(ps[i]), ans++;
    printf("%d\n", ans);
    return 0;
}
