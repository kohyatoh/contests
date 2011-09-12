#include <stdio.h>

double dp[100000];

int main() {
    puts("Cards  Overhang");
    dp[0] = 0;
    for(int i=1; i<100000; i++) dp[i] = dp[i-1] + 1.0/(i*2);
    int n;
    while(scanf("%d", &n)!=EOF) printf("%5d%10.3f\n", n, dp[n]);
}
