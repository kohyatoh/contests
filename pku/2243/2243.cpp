#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

const int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2};
int vis[10][10];
char a[8], b[8];

int main() {
    while(scanf(" %s%s", a, b)!=EOF) {
        int sx=a[0]-'a', sy=a[1]-'1', tx=b[0]-'a', ty=b[1]-'1';
        memset(vis, 0, sizeof(vis));
        queue<pair<int, pair<int, int> > > q;
        q.push(mp(0, mp(sx, sy)));
        while(!q.empty()) {
            pair<int, pair<int, int> > v(q.front());
            q.pop();
            int cx=v.second.first, cy=v.second.second;
            if(cx<0 || cx>7 || cy<0 || cy>7 || vis[cx][cy]) continue;
            vis[cx][cy] = 1;
            if(cx==tx && cy==ty) {
                printf("To get from %s to %s takes %d knight moves.\n", a, b, v.first);
                break;
            }
            rep(d, 8) {
                int nx=cx+dx[d], ny=cy+dy[d];
                if(nx<0 || nx>7 || ny<0 || ny>7 || vis[nx][ny]) continue;
                q.push(mp(v.first+1, mp(nx, ny)));
            }
        }
    }
    return 0;
}

