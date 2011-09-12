#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int tw[6] = {5, 3, 4, 1, 2, 0};
int T, n, dice[20000][6];

int main() {
    scanf("%d", &T);
    rep(q, T) {
        scanf("%d", &n);
        rep(i, n) rep(j, 6) scanf("%d", dice[i]+j);
        int ans=0;
        rep(k, 6) {
            int top=k+1, bot, dir, s=0;
            rep(i, n) {
                bot = top;
                rep(j, 6) if(dice[i][j]==bot) dir=j;
                top = dice[i][tw[dir]];
                int mx=0;
                rep(j, 6) if(dice[i][j]!=top && dice[i][j]!=bot) {
                    if(mx<dice[i][j]) mx=dice[i][j];
                }
                s+=mx;
            }
            if(ans<s) ans=s;
        }
        printf("%d\n", ans);
    }
    return 0;
}

