#include <stdio.h>
#include <string>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int K, w, h, n, m;
int x[200], y[200], dir[200];
int rn[200], re[200];
char ac[200];
char f[120][120];

void check() {
    rep(i, m) {
        int k=rn[i]-1;
        if(ac[i]=='L') dir[k]=(dir[k]+3*re[i])%4;
        else if(ac[i]=='R') dir[k]=(dir[k]+re[i])%4;
        else {
            rep(l, re[i]) {
                f[x[k]][y[k]]=0;
                x[k]+=dx[dir[k]], y[k]+=dy[dir[k]];
                if(f[x[k]][y[k]]) {
                    if(f[x[k]][y[k]]<0) printf("Robot %d crashes into the wall\n", k+1);
                    else printf("Robot %d crashes into robot %d\n", k+1, f[x[k]][y[k]]);
                    return ;
                }
                f[x[k]][y[k]]=k+1;
            }
        }
    }
    printf("OK\n");
}

int main() {
    std::string dirs = "NESW";
    scanf("%d", &K);
    rep(q, K) {
        scanf("%d%d%d%d", &w, &h, &n, &m);
        rep(i, w+2) rep(j, h+2) f[i][j]=-1;
        rep(i, w) rep(j, h) f[i+1][j+1]=0;
        rep(i, n) {
            char ch;
            scanf("%d%d %c", x+i, y+i, &ch);
            dir[i]=dirs.find(ch);
            f[x[i]][y[i]]=i+1;
        }
        rep(i, m) scanf("%d %c %d", rn+i, ac+i, re+i);
        check();
    }
    return 0;
}
