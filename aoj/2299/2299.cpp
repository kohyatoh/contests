#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int M, N;
char f[512][512];

bool click(int x, int y, char target) {
    if(f[x][y]!='.') return false;
    int tx[4], ty[4];
    rep(d, 4) {
        tx[d] = x, ty[d] = y;
        while(f[tx[d]][ty[d]]=='.') {
            tx[d] += dx[d];
            ty[d] += dy[d];
        }
    }
    rep(i, 4) if(f[tx[i]][ty[i]]==target) {
        rep(j, i) if(f[tx[j]][ty[j]]==target) {
            f[tx[i]][ty[i]] = f[tx[j]][ty[j]] = '.';
            return true;
        }
    }
    return false;
}

int xof[32][2], yof[32][2];

int main() {
    scanf("%d%d", &M, &N);
    memset(f, '#', sizeof(f));
    rep(i, M) rep(j, N) scanf(" %c", f[i+1]+j+1);
    memset(xof, -1, sizeof(xof));
    memset(yof, -1, sizeof(yof));
    rep(i, M) rep(j, N) if(f[i+1][j+1]!='.') {
        const int ix = f[i+1][j+1]-'A';
        if(xof[ix][0]==-1) xof[ix][0]=i+1, yof[ix][0]=j+1;
        else xof[ix][1]=i+1, yof[ix][1]=j+1;
    }
    bool nothing = false;
    int ans = 0;
    while(!nothing) {
        nothing = true;
        rep(i, 32) if(xof[i][0]!=-1) {
            bool hit = false;
            if(xof[i][0]==xof[i][1]) {
                hit = click(xof[i][0], (yof[i][0]+yof[i][1])/2, i+'A');
            }
            else if(yof[i][0]==yof[i][1]) {
                hit = click((xof[i][0]+xof[i][1])/2, yof[i][0], i+'A');
            }
            else {
                hit |= click(xof[i][0], yof[i][1], i+'A');
                hit |= click(xof[i][1], yof[i][0], i+'A');
            }
            if(hit) {
                nothing = false;
                xof[i][0] = -1;
                ans += 2;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
