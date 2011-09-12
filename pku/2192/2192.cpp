#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, memo[300][300];
char s[3][500];

bool can(int i, int j) {
    if(s[2][i+j]==0) return true;
    if(memo[i][j]!=-1) return memo[i][j];
    bool ans=false;
    if(s[0][i]==s[2][i+j]) ans|=can(i+1, j);
    if(s[1][j]==s[2][i+j]) ans|=can(i, j+1);
    return (memo[i][j]=ans);
}

int main() {
    scanf("%d", &T);
    rep(q, T) {
        scanf(" %s%s%s", s[0], s[1], s[2]);
        memset(memo, -1, sizeof(memo));
        printf("Data set %d: %s\n", q+1, can(0, 0) ? "yes" : "no");
    }
    return 0;
}
