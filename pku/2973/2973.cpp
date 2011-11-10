#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int cnt[1024][32], xs[32], y;
char buf[32];

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        memset(cnt, 0, sizeof(cnt));
        rep(k, n) {
            scanf(" %s", buf);
            for(int i=0; buf[i]; i++) cnt[k][buf[i]-'A']++;
        }
        scanf(" %s", buf);
        memset(xs, 0, sizeof(xs));
        y = 0;
        for(int i=0; buf[i]; i++) {
            if(buf[i]=='_') y++;
            else xs[buf[i]-'A']++;
        }
        int ans = 0;
        rep(k, n) {
            int s = 0;
            rep(i, 26) if(cnt[k][i]>xs[i]) s += cnt[k][i]-xs[i];
            if(s<=y) ans++;
        }
        printf("%d\n", ans);
    }
}
