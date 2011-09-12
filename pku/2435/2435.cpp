#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
char of[5] = "ENWS";

int w, h;
char f[100][100];
int pre[100][100];

int main() {
    scanf("%d%d", &h, &w);
    rep(i, 100) rep(j, 100) f[i][j]='.';
    rep(j, 2*h-1) rep(i, 2*w-1) scanf(" %c", f[i+1]+j+1);
    queue<pair<int, int> > q;
    rep(i, 100) rep(j, 100) if(f[i][j]=='S') {
        q.push(mp(i, j));
        pre[i][j] = -1;
        f[i][j] = '.';
    }
    int ex=-1, ey=-1;
    while(!q.empty()) {
        int x=q.front().first, y=q.front().second;
        q.pop();
        rep(d, 4) {
            int nx=x+dx[d], ny=y+dy[d];
            if(f[nx][ny]=='E') {
                ex=nx, ey=ny;
                pre[nx][ny] = d;
                goto bfs_break;
            }
            else if(f[nx][ny]!='.') {
                q.push(mp(nx, ny));
                pre[nx][ny] = d;
                f[nx][ny] = '.';
            }
        }
    }
bfs_break:
    vector<pair<int, int> > v;
    while(pre[ex][ey]!=-1) {
        if(v.size()>0 && v.back().first==pre[ex][ey]) v.back().second++;
        else v.push_back(mp(pre[ex][ey], 1));
        int d=pre[ex][ey];
        ex-=dx[d], ey-=dy[d];
    }
    for(int i=v.size()-1; i>=0; i--) {
        printf("%c %d\n", of[v[i].first], v[i].second/2);
    }
    return 0;
}

