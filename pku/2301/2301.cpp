#include <stdio.h>
#define rep(i, n) for(int i=0; i<n; i++)

int main() {
    int n;
    scanf("%d", &n);
    rep(i, n) {
        int s, d;
        scanf("%d%d", &s, &d);
        if((s+d)%2==0 && s>=d) printf("%d %d\n", (s+d)/2, (s-d)/2);
        else printf("impossible\n");
    }
    return 0;
}

