#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int R, C, M, pc[64][64], on[64][64], off[64][64], px[64][64], py[64][64];
char f[64][64];
vector<int> zt[64][64];

void rec(int cx, int cy) {
    rep(d, 4) {
        const int x=cx+dx[d], y=cy+dy[d];
        if(f[x][y]!='#' && px[x][y]==-1) {
            px[x][y] = cx;
            py[x][y] = cy;
            rec(x, y);
        }
    }
}

int main() {
    memset(f, '#', sizeof(f));
    scanf("%d%d%d", &R, &C, &M);
    rep(i, R) rep(j, C) scanf(" %c", &f[i+1][j+1]);
    rep(i, R) rep(j, C) scanf("%d", &pc[i+1][j+1]);
    rep(i, R) rep(j, C) scanf("%d", &on[i+1][j+1]);
    rep(i, R) rep(j, C) scanf("%d", &off[i+1][j+1]);
    int cx=-1, cy=-1, t=0;
    rep(i, M) {
        int x, y;
        scanf("%d%d", &x, &y);
        x++, y++;
        if(i>0) {
            memset(px, -1, sizeof(px));
            rec(x, y);
            while(cx!=x || cy!=y) {
                zt[cx][cy].push_back(t++);
                int tx=cx, ty=cy;
                cx = px[tx][ty], cy = py[tx][ty];
            }
        }
        cx = x; cy = y;
    }
    zt[cx][cy].push_back(t);
    Int ans = 0;
    rep(i, R+2) rep(j, C+2) if(zt[i][j].size()) {
        ans += on[i][j];
        ans += off[i][j];
        rep(k, zt[i][j].size()-1) {
            int dt = zt[i][j][k+1]-zt[i][j][k];
            ans += min((Int)on[i][j]+off[i][j], (Int)dt*pc[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}

