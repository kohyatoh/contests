#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, dp[1000100];
char s[1000100];

int main() {
    for(int q=0;; q++) {
        scanf("%d", &n);
        if(n==0) return 0;
        scanf(" %s", s);
        printf("Test case #%d\n", q+1);
        int j = dp[0] = -1;
        for(int i=1; i<=n; i++) {
            while(j>=0 && s[j]!=s[i-1]) j=dp[j];
            dp[i]=++j;
            if(i%(i-dp[i])==0) {
                int k=i/(i-dp[i]);
                if(k>1) printf("%d %d\n", i, k);
            }
        }
        printf("\n");
    }
}

