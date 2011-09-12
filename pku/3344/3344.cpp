#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int cx, cy, cd, k;
char f[8][8], inst[10], info[10], dirs[]=">v<^";
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int valid(int x, int y) { return 0<=x && x<8 && 0<=y && y<8; }

int main() {
    for(;;) {
        scanf(" %c", f[0]);
        if(f[0][0]=='-') return 0;
        rep(i, 8) rep(j, 8) if(i || j) scanf(" %c", f[i]+j);
        rep(i, 8) rep(j, 8) rep(d, 4) if(dirs[d]==f[i][j]) {
            cx=i, cy=j, cd=d;
            f[i][j] = '.';
        }
        for(;;) {
            scanf(" %s", inst);
            if(inst[0]=='#') break;
            else if(inst[0]=='t') {
                scanf(" %s", info);
                if(info[0]=='r') cd=(cd+1)%4;
                else if(info[0]=='b') cd=(cd+2)%4;
                else cd=(cd+3)%4;
            }
            else {
                scanf("%d", &k);
                while(k--) {
                    if(!valid(cx+dx[cd], cy+dy[cd])) break;
                    cx+=dx[cd], cy+=dy[cd];
                    char ch='.';
                    int x=cx, y=cy;
                    while(valid(x, y) && f[x][y]!='.') {
                        swap(ch, f[x][y]);
                        x+=dx[cd], y+=dy[cd];
                    }
                    if(valid(x, y)) f[x][y]=ch;
                }
            }
        }
        f[cx][cy] = dirs[cd];
        rep(i, 8) {
            rep(j, 8) putchar(f[i][j]);
            putchar('\n');
        }
        putchar('\n');
    }
}

