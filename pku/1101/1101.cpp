#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define INF (1<<30)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int w, h, dp[128][128];
char f[128][128], buf[128];

int bfs(int sx, int sy, int ex, int ey) {
    rep(i, w) rep(j, h) dp[i][j] = INF;
    queue<pair<int, int> > q;
    q.push(mp(sx, sy));
    dp[sx][sy] = 0;
    while(!q.empty()) {
        const pair<int, int> v(q.front());
        q.pop();
        const int x = v.first;
        const int y = v.second;
        if(dp[x][y]>0 && f[x][y]=='X') continue;
        rep(d, 4) {
            int cx = x, cy = y;
            do {
                cx += dx[d], cy += dy[d];
                if(cx<0 || cx>=w || cy<0 || cy>=h) break;
                if(cx==ex && cy==ey) return dp[x][y]+1;
                if(dp[cx][cy]==INF) {
                    dp[cx][cy] = dp[x][y]+1;
                    q.push(mp(cx, cy));
                }
            } while(f[cx][cy]!='X');
        }
    }
    return -1;
}

int main() {
    for(int _t=0;; _t++) {
        gets(buf);
        sscanf(buf, "%d%d", &w, &h);
        if(w==0 && h==0) return 0;
        memset(f, ' ', sizeof(f));
        rep(j, h) {
            gets(buf);
            rep(i, w) f[i+1][j+1] = buf[i];
        }
        w += 2, h += 2;
        printf("Board #%d:\n", _t+1);
        for(int _p=0;; _p++) {
            gets(buf);
            int sx, sy, ex, ey;
            sscanf(buf, "%d%d%d%d", &sx, &sy, &ex, &ey);
            if(sx==0 && sy==0 && ex==0 && ey==0) break;
            printf("Pair %d: ", _p+1);
            const int ans = bfs(sx, sy, ex, ey);
            if(ans==-1) puts("impossible.");
            else printf("%d segments.\n", ans);
        }
        puts("");
    }
}
