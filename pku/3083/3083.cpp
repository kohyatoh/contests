#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#ifdef DEBUGRUN
#define log(x) (cerr<<#x"="<<(x)<<endl)
#else
#define log(x) ((void)(0))
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int w, h;
char f[64][64];

int go(int x, int y, int dd) {
    int dir=0, step=0;
    while(f[x][y]!='E') {
        dir = (dir-dd+4)%4;
        rep(_, 4) {
            const int nx=x+dx[dir], ny=y+dy[dir];
            if(0<=nx && nx<w && 0<=ny && ny<h && f[nx][ny]!='#') {
                x = nx;
                y = ny;
                break;
            }
            dir = (dir+dd+4)%4;
        }
        step++;
    }
    return step+1;
}

int bfs(int sx, int sy) {
    queue<pair<int, pair<int, int> > > q;
    q.push(mp(0, mp(sx, sy)));
    while(!q.empty()) {
        pair<int, pair<int, int> > v(q.front());
        q.pop();
        const int x = v.second.first;
        const int y = v.second.second;
        if(f[x][y]=='E') return v.first+1;
        if(f[x][y]=='#') continue;
        f[x][y] = '#';
        rep(d, 4) {
            const int nx=x+dx[d], ny=y+dy[d];
            if(0<=nx && nx<w && 0<=ny && ny<h) {
                q.push(mp(v.first+1, mp(nx, ny)));
            }
        }
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &w, &h);
        rep(j, h) rep(i, w) scanf(" %c", &f[i][j]);
        rep(i, w) rep(j, h) if(f[i][j]=='S') {
            printf("%d ", go(i, j, -1));
            printf("%d ", go(i, j, 1));
            printf("%d\n", bfs(i, j));
        }
    }
    return 0;
}
