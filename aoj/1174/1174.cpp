#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int h, w, c, p[16][16], q[16][16];

int draw(int x, int y, int f, int t) {
    if(f==t || x<0 || x>=h || y<0 || y>=w) return 0;
    if(q[x][y]!=f) return 0;
    q[x][y] = t;
    int ans = 1;
    rep(i, 4) ans += draw(x+dx[i], y+dy[i], f, t);
    return ans;
}

int main() {
    for(;;) {
        scanf("%d%d%d", &h, &w, &c);
        if(h==0 && w==0 && c==0) return 0;
        rep(i, h) rep(j, w) scanf("%d", p[i]+j);
        int kk = 1;
        rep(i, 4) kk *= 6;
        int ans = 0;
        rep(b, kk) {
            rep(i, h) rep(j, w) q[i][j] = p[i][j];
            int t = b;
            rep(i, 4) {
                draw(0, 0, q[0][0], t%6+1);
                t /= 6;
            }
            draw(0, 0, q[0][0], c);
            ans = max(ans, draw(0, 0, q[0][0], 0));
        }
        printf("%d\n", ans);
    }
}
