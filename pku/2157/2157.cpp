#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
char f[30][30];
int w, h, vis[30][30], cnt[10];

int main() {
    for(;;) {
        scanf("%d%d", &h, &w);
        if(h==0 && w==0) return 0;
        rep(i, 30) rep(j, 30) f[i][j]='X';
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        rep(j, h) rep(i, w) scanf(" %c", f[i+1]+j+1);
        h+=2, w+=2;
        queue<pair<int, int> > q;
        rep(i, w) rep(j, h) {
            if(f[i][j]=='S') q.push(mp(i, j));
            if('a'<=f[i][j] && f[i][j]<='e') cnt[f[i][j]-'a']++;
        }
        bool yes=false;
        while(!q.empty()) {
            pair<int, int> v(q.front());
            q.pop();
            int x=v.first, y=v.second;
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            if(f[x][y]=='G') { yes=true; break; }
            if('a'<=f[x][y] && f[x][y]<='e' && --cnt[f[x][y]-'a']==0) {
                rep(i, w) rep(j, h) if(f[i][j]-'A'==f[x][y]-'a') {
                    f[i][j] = '.';
                    rep(d, 4) if(vis[i+dx[d]][j+dy[d]]) q.push(mp(i, j));
                }
            }
            rep(d, 4) {
                int nx=x+dx[d], ny=y+dy[d];
                if(f[nx][ny]=='X' || ('A'<=f[nx][ny] && f[nx][ny]<='E')) continue;
                q.push(mp(nx, ny));
            }
        }
        puts(yes ? "YES" : "NO");
    }
}
