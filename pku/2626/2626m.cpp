#include <stdio.h>
#include <algorithm>
using namespace std;

int w, b, dp[20][20];

int main() {
    while(scanf("%d%d", &w, &b)!=EOF) {
        for(int i=15; i>=0; i--) for(int j=15; j>=0; j--) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+w);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]+b);
        }
    }
    printf("%d\n", dp[15][15]);
    return 0;
}
