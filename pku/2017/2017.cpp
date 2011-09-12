#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==-1) return 0;
        int s, t, p=0, ans=0;
        rep(i, n) {
            scanf("%d%d", &s, &t);
            ans += s*(t-p);
            p = t;
        }
        printf("%d miles\n", ans);
    }
}
