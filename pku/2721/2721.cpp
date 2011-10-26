#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int C[32][32];

int main() {
    C[0][0] = 1;
    rep(i, 31) rep(j, 31) C[i+1][j]+=C[i][j], C[i+1][j+1]+=C[i][j];
    for(;;) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a==-1 && b==-1) return 0;
        double ans = (double)C[a+b][a]*C[26-a-b][13-a]/C[26][13];
        if(a!=b) ans *= 2;
        printf("%d-%d split: %.8f\n", a, b, ans);
    }
}
