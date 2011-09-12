#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, f[19][19];
int dx[4] = {-1, 0, 1, 1};
int dy[4] = {1, 1, 1, 0};

bool win(int x, int y, int d) {
    rep(dir, 4) {
        int c1=0, c2=0, cx=x-dx[dir], cy=y-dy[dir];
        if(0<=cx && cx<19 && 0<=cy && cy<19 && f[cx][cy]==d) continue;
        rep(k, 6) {
            cx+=dx[dir], cy+=dy[dir];
            if(0<=cx && cx<19 && 0<=cy && cy<19 && f[cx][cy]==d) {
                if(k<5) c1++;
                c2++;
            }
        }
        if(c1==5 && c2==5) return true;
    }
    return false;
}

void solve() {
    rep(d, 2) rep(i, 19) rep(j, 19) {
        if(win(i, j, d+1)) {
            printf("%d\n%d %d\n", d+1, i+1, j+1);
            return;
        }
    }
    printf("0\n");
}

int main() {
    scanf("%d", &T);
    rep(q, T) {
        rep(i, 19) rep(j, 19) scanf("%d", f[i]+j);
        solve();
    }
    return 0;
}

