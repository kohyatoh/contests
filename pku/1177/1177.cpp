#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

struct R { int x1, y1, x2, y2; };

void merge(vector<pair<int, int> > &ys) {
    sort(ys.begin(), ys.end());
    int m = 0;
    rep(i, ys.size()) {
        if(i==0 || ys[m-1].second<ys[i].first) ys[m++] = ys[i];
        else ys[m-1].second = max(ys[m-1].second, ys[i].second);
    }
    ys.resize(m);
}

int n;
R rs[2][6000];

int f(R *as, int x, int y1, int y2) {
    vector<pair<int, int> > ys;
    rep(i, n) if(as[i].x1<=x && x<=as[i].x2 && as[i].y1<y2 && as[i].y2>y1) {
        ys.push_back(mp(max(y1, as[i].y1), min(y2, as[i].y2)));
    }
    merge(ys);
    int ans = y2-y1;
    rep(i, ys.size()) ans -= ys[i].second-ys[i].first;
    return ans;
}

int main() {
    scanf("%d", &n);
    rep(i, n) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1>x2) swap(x1, x2);
        if(y1>y2) swap(y1, y2);
        rs[0][i].x1=x1*3; rs[0][i].y1=y1; rs[0][i].x2=x2*3; rs[0][i].y2=y2;
        rs[1][i].x1=y1*3; rs[1][i].y1=x1; rs[1][i].x2=y2*3; rs[1][i].y2=x2;
    }
    int ans = 0;
    rep(dir, 2) {
        vector<int> xs;
        rep(k, n) {
            xs.push_back(rs[dir][k].x1-1);
            xs.push_back(rs[dir][k].x2+1);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        vector<vector<pair<int, int> > > xxs(xs.size());
        rep(k, n) {
            const int ix = lower_bound(xs.begin(), xs.end(), rs[dir][k].x1-1)-xs.begin();
            const int jx = lower_bound(xs.begin(), xs.end(), rs[dir][k].x2+1)-xs.begin();
            xxs[ix].push_back(mp(rs[dir][k].y1, rs[dir][k].y2));
            xxs[jx].push_back(mp(rs[dir][k].y1, rs[dir][k].y2));
        }
        rep(k, xs.size()) {
            merge(xxs[k]);
            rep(i, xxs[k].size()) {
                ans += f(rs[dir], xs[k], xxs[k][i].first, xxs[k][i].second);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
