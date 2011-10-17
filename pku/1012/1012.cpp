#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

bool good(int n, int m) {
    int x = 0, sz = 2*n;
    rep(_, n) {
        x = (x+m)%sz;
        if(x<n) return false;
        sz--;
    }
    return true;
}

int memo[20];

int solve(int n) {
    if(memo[n]!=0) return memo[n];
    for(int i=1; ; i++) if(good(n, i)) {
        return memo[n] = i+1;
    }
}

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        printf("%d\n", solve(n));
    }
}
