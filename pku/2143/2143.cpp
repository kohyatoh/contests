#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, p, peg[10][10], fie[10][10][10];

int dx[13] = { 1, 0, 0, 1, 1, 0, 1, -1, 0, 1, 1, 1, -1};
int dy[13] = { 0, 1, 0, 1, 0, 1, -1, 0, 1, 1, 1, -1, 1};
int dz[13] = { 0, 0, 1, 0, 1, 1, 0, 1, -1, 1, -1, 1, 1};

int check(int color) {
    rep(d, 13) {
        rep(x, n) rep(y, n) rep(z, n) {
            int c=0, cx=x, cy=y, cz=z;
            while(0<=cx && cx<n && 0<=cy && cy<n && 0<=cz && cz<n) {
                if(fie[cx][cy][cz]!=color) c=0;
                else if(++c>=m) return 1;
                cx+=dx[d], cy+=dy[d], cz+=dz[d];
            }
        }
    }
    return 0;
}

int main() {
    for(;;) {
        scanf("%d%d%d", &n, &m, &p);
        if(n==0) return 0;
        rep(i, 10) rep(j, 10) peg[i][j]=0;
        rep(i, 10) rep(j, 10) rep(k, 10) fie[i][j][k]=-1;
        int win=-1, at=-1;
        rep(i, p) {
            int x, y;
            scanf("%d%d", &x, &y);
            fie[x-1][y-1][peg[x-1][y-1]++]=i%2;
            if(win==-1 && check(i%2)) win=i%2, at=i+1;
        }
        if(win==-1) printf("Draw\n");
        else printf("%s %d\n", win?"White":"Black", at);
    }
}

