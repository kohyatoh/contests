#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, pre[128][256];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        memset(pre, -1, sizeof(pre));
        pre[0][0] = 0;
        for(int k=0, dig=1; ; k++, dig=dig*10%n) {
            rep(i, n) if(pre[k][i]!=-1) pre[k+1][(i+dig)%n] = i;
            if(pre[k+1][0]!=-1) {
                int cur = 0;
                for(int i=k+1; i>0; i--) {
                    putchar(i==k+1 || pre[i][cur]!=cur ? '1' : '0');
                    cur = pre[i][cur];
                }
                putchar('\n');
                break;
            }
            rep(i, n) if(pre[k][i]!=-1) pre[k+1][i] = i;
        }
    }
}
