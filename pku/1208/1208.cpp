#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n;
vector<int> xs[32];

pair<int, int> find(int x) {
    rep(i, n) rep(j, xs[i].size()) if(xs[i][j]==x) return mp(i, j);
    return mp(-1, -1);
}

int main() {
    scanf("%d", &n);
    rep(i, n) xs[i].push_back(i);
    char op[8], ty[8];
    int u, v;
    for(;;) {
        scanf(" %s", &op);
        if(op[0]=='q') break;
        scanf("%d%s%d", &u, ty, &v);
        pair<int, int> xx(find(u)), yy(find(v));
        const int xi = xx.first, xj = xx.second;
        const int yi = yy.first, yj = yy.second;
        if(xi==yi) continue;
        if(op[0]=='m') {
            while(xj<(int)xs[xi].size()-1) {
                xs[xs[xi].back()].push_back(xs[xi].back());
                xs[xi].pop_back();
            }
        }
        if(ty[2]=='n') {
            while(yj<(int)xs[yi].size()-1) {
                xs[xs[yi].back()].push_back(xs[yi].back());
                xs[yi].pop_back();
            }
        }
        reverse(xs[xi].begin()+xj, xs[xi].end());
        while(xj<=(int)xs[xi].size()-1) {
            xs[yi].push_back(xs[xi].back());
            xs[xi].pop_back();
        }
    }
    rep(k, n) {
        printf("%d:", k);
        rep(i, xs[k].size()) printf(" %d", xs[k][i]);
        printf("\n");
    }
    return 0;
}
