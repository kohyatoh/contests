#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int N;
    while(scanf("%d", &N)!=EOF) {
        bool ok = false;
        rep(i, 32) if(N==1<<i) ok = true;
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
