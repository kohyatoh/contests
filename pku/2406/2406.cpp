#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
char str[1000010];

int main() {
    for(;;) {
        gets(str);
        n = strlen(str);
        if(n==1 && *str=='.') return 0;
        int ans=1;
        for(int d=2; d<=n; d++) if(n%d==0) {
            int m=n/d;
            bool f=true;
            rep(i, n-m) if(str[i]!=str[i+m]) { f=false; break; }
            if(f) ans=d;
        }
        printf("%d\n", ans);
    }
}
