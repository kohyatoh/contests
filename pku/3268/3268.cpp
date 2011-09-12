#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, m, x, g[1010][1010], d[3][1010];

int main() {
    scanf("%d%d%d", &n, &m, &x);
    rep(i, m) {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        g[a-1][b-1]=t;
    }
    rep(k, 2) {
        rep(i, n) d[k][i]=-1;
        int c=0;
        priority_queue<pair<int, int> > q;
        q.push(mp(0, x-1));
        while(c<n) {
            pair<int, int> v=q.top(); q.pop();
            if(d[k][v.second]>=0) continue;
            d[k][v.second] = -v.first;
            c++;
            rep(i, n) if(d[k][i]==-1 && g[v.second][i]!=0) {
                q.push(mp(v.first-g[v.second][i], i));
            }
        }
        rep(i, n) rep(j, i) swap(g[i][j], g[j][i]);
        rep(i, n) d[2][i]+=d[k][i];
    }
    printf("%d\n", *max_element(d[2], d[2]+n));
    return 0;
}
