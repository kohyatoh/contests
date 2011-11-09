#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int cnt[1024];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        rep(_, n) {
            char ch;
            int a, b;
            scanf(" %c%d%d", &ch, &a, &b);
            for(int i=a; i<b; i++) cnt[i]++;
        }
        rep(i, 1024) if(cnt[i]) putchar('A'+cnt[i]-1);
        putchar('\n');
    }
    return 0;
}
