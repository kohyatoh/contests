#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

bool v[65536];

int main() {
    for(;;) {
        int c, s;
        scanf("%d%d", &c, &s);
        if(c==0 && s==0) return 0;
        int cc = 1;
        rep(i, s) cc *= c;
        memset(v, 0, sizeof(v));
        int ans = 0;
        rep(b, cc) if(!v[b]) {
            ans++;
            int p = b, k = 0;
            rep(i, s) {
                k = k*c+p%c;
                p /= c;
            }
            p = b;
            rep(i, s) {
                v[p] = v[k] = true;
                p += p%c*cc;
                k += k%c*cc;
                p /= c;
                k /= c;
            }
        }
        printf("%d\n", ans);
    }
}
