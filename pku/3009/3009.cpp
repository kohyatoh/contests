#include <stdio.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<10)

int w, h, f[20][20]; // f[w][h]
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

bool out(int x, int y) {
    return x<0 || x>=w || y<0 || y>=h;
}

int rec(int x, int y, int z) {
    if(z>=10) return INF;
    int ans = INF;
    rep(d, 4) {
        int cx=x+dx[d], cy=y+dy[d];
        if(out(cx, cy) || f[cx][cy]==1) continue;
        for(; !out(cx, cy); cx+=dx[d], cy+=dy[d]) {
            if(f[cx][cy]==3) return z+1;
            if(f[cx][cy]==1) {
                f[cx][cy] = 0;
                ans = std::min(ans, rec(cx-dx[d], cy-dy[d], z+1));
                f[cx][cy] = 1;
                break;
            }
        }
    }
    return ans;
}

int main() {
    for(;;) {
        scanf("%d%d", &w, &h);
        if(w==0 && h==0) return 0;
        rep(j, h) rep(i, w) scanf("%d", f[i]+j);
        rep(i, w) rep(j, h) if(f[i][j]==2) {
            int ans = rec(i, j, 0);
            printf("%d\n", ans<INF ? ans : -1);
        }
    }
}

