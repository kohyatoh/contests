#include <stdio.h>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int w, h, dp[100][100];
char f[100][100];

int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

int main() {
    string dirs="ESWN";
    for(;;) {
        int cx, cy=1;
        scanf("%d%d%d", &h, &w, &cx);
        if(h==0) return 0;
        rep(i, 100) rep(j, 100) dp[i][j]=-1;
        rep(i, 100) rep(j, 100) f[i][j]=0;
        rep(j, h) rep(i, w) scanf(" %c", f[i+1]+j+1);
        int s=0;
        while(f[cx][cy] && dp[cx][cy]<0) {
            dp[cx][cy]=s++;
            int d=dirs.find(f[cx][cy]);
            cx+=dx[d], cy+=dy[d];
        }
        if(f[cx][cy]==0) printf("%d step(s) to exit\n", s);
        else printf("%d step(s) before a loop of %d step(s)\n", dp[cx][cy], s-dp[cx][cy]);
    }
}
