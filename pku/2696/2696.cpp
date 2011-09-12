#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, p[9], dp[2000];

int mod(int a, int m) {
    if(a>=0) return a%m;
    else return (m-(-a)%m)%m;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        rep(i, 9) scanf("%d", p+i);
        rep(i, 1001) {
            if(i<3) dp[i]=p[i];
            else {
                dp[i] =
                    i%2 ?  mod(p[3]*dp[i-1]+p[4]*dp[i-2]-p[5]*dp[i-3], p[6])
                        :  mod(p[5]*dp[i-1]-p[3]*dp[i-2]+p[4]*dp[i-3], p[7]);
            }
        }
        printf("%d\n", dp[p[8]]);
    }
    return 0;
}
