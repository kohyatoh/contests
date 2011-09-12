#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[3000], b[3000];

bool jolly() {
    rep(i, 3000) b[i]=0;
    rep(i, n-1) {
        int d=abs(a[i+1]-a[i]);
        if(d>=n || b[d]) return false;
        b[d]=1;
    }
    return true;
}

int main() {
    while(scanf("%d", &n)!=EOF) {
        rep(i, n) scanf("%d", a+i);
        puts(jolly() ? "Jolly" : "Not jolly");
    }
    return 0;
}

