#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct F {
    int m[9][9], f[9][9], c[9][9], r;

    void fill(int x, int y, int a) {
        rep(i, 9) if(f[x][i]&(1<<a)) c[x][i]--, f[x][i]^=1<<a;
        rep(i, 9) if(f[i][y]&(1<<a)) c[i][y]--, f[i][y]^=1<<a;
        x=x/3*3, y=y/3*3;
        rep(i, 3) rep(j, 3) if(f[x+i][y+j]&(1<<a)) c[x+i][y+j]--, f[x+i][y+j]^=1<<a;
    }

    bool rec() {
        for(bool t=true; t; ) {
            t = false;
            rep(i, 9) rep(j, 9) if(c[i][j]==1) {
                rep(k, 9) if(f[i][j]&(1<<k)) {
                    fill(i, j, k);
                    m[i][j]=k+1;
                    c[i][j] = 0;
                    r--;
                    t = true;
                }
            }
            if(r==0) return true;
            rep(i, 9) rep(j, 9) if(m[i][j]==0 && c[i][j]==0) return false;
        }
        int mc=10, x=-1, y=-1;
        rep(i, 9) rep(j, 9) if(c[i][j]>0 && c[i][j]<mc) mc=c[i][j], x=i, y=j;
        if(mc==10) return false;
        rep(k, 9) if(f[x][y]&(1<<k)) {
            F f2(*this);
            f2.fill(x, y, k);
            f2.m[x][y]=k+1;
            f2.c[x][y]=0;
            f2.r--;
            if(f2.rec()) {
                rep(i, 9) rep(j, 9) m[i][j]=f2.m[i][j];
                return true;
            }
        }
        return false;
    }
};

int T;
char ch[9][9];

int main() {
    scanf("%d", &T);
    while(T--) {
        F f;
        rep(i, 9) rep(j, 9) scanf(" %c", ch[i]+j);
        f.r=81;
        rep(i, 9) rep(j, 9) {
            f.m[i][j] = ch[i][j]-'0';
            f.f[i][j] = -1;
            f.c[i][j] = 9;
        }
        rep(i, 9) rep(j, 9) if(f.m[i][j]) {
            f.fill(i, j, f.m[i][j]-1);
            f.f[i][j] = 0;
            f.c[i][j] = 0;
            f.r--;
        }
        f.rec();
        rep(i, 9) {
            rep(j, 9) printf("%d", f.m[i][j]);
            printf("\n");
        }
    }
    return 0;
}
