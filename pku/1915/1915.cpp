#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int T, l, sx, sy, ex, ey, f[500][500];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main() {
    scanf("%d", &T);
    rep(q, T) {
        scanf("%d%d%d%d%d", &l, &sx, &sy, &ex, &ey);
        rep(i, l) rep(j, l) f[i][j]=-1;
        queue<pair<int, pair<int, int> > > q;
        q.push(mp(0, mp(sx, sy)));
        while(!q.empty()) {
            pair<int, pair<int, int> > v=q.front();
            q.pop();
            int cx=v.second.first, cy=v.second.second;
            if(cx<0 || cx>=l || cy<0 || cy>=l || f[cx][cy]!=-1) continue;
            f[cx][cy] = v.first;
            if(cx==ex && cy==ey) break;
            rep(d, 8) q.push(mp(v.first+1, mp(cx+dx[d], cy+dy[d])));
        }
        printf("%d\n", f[ex][ey]);
    }
}

