#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int of(int x, int y) {
    if(x>0 && y>0) return 0;
    else if(x<0 && y>0) return 1;
    else if(x<0 && y<0) return 2;
    else return 3;
}

vector<pair<double, pair<int, int> > > v[4];

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    while(scanf("%d%d", &x, &y)!=EOF) {
        v[of(x, y)].push_back(mp(1.*y/x, mp(x, y)));
    }
    rep(i, 4) sort(v[i].begin(), v[i].end());
    int s=0;
    rep(i, 4) if(v[i].size()==0) s=i;
    printf("(%d,%d)\n", 0, 0);
    rep(i, 4) rep(j, v[(i+s)%4].size()) {
        pair<int, int> p(v[(i+s)%4][j].second);
        printf("(%d,%d)\n", p.first, p.second);
    }
    return 0;
}
