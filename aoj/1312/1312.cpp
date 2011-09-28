#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define P (3)

int b64(char ch) {
    if('A'<=ch && ch<='Z') return ch-'A';
    if('a'<=ch && ch<='z') return ch-'a'+26;
    if('0'<=ch && ch<='9') return ch-'0'+52;
    return ch=='+' ? 62 : 63;
}

int w, h, p, f[1024][1024], m[128][128], tmp[128][128];
char tf[1000][200], tm[100][20];
typedef unsigned long long hash;
hash hori[1024][1024], hs[8];

int main() {
    for(;;) {
        scanf("%d%d%d", &w, &h, &p);
        if(w==0 && h==0 && p==0) return 0;
        rep(i, h) scanf(" %s", tf[i]);
        rep(i, p) scanf(" %s", tm[i]);
        memset(f, 0, sizeof(f));
        rep(i, h) for(int j=0; tf[i][j]; j++) {
            const int x = b64(tf[i][j]);
            rep(k, 6) if(x&(1<<k)) f[i][j*6+5-k] = 1;
        }
        memset(m, 0, sizeof(m));
        rep(i, p) for(int j=0; tm[i][j]; j++) {
            const int x = b64(tm[i][j]);
            rep(k, 6) if(x&(1<<k)) m[i][j*6+5-k] = 1;
        }
        rep(d, 8) {
            memcpy(tmp, m, sizeof(m));
            rep(i, p) rep(j, p) m[p-1-j][i] = tmp[i][j];
            if(d==4) {
                memcpy(tmp, m, sizeof(m));
                rep(i, p) rep(j, p) m[i][p-1-j] = tmp[i][j];
            }
            hs[d] = 0;
            rep(i, p) rep(j, p) hs[d] = hs[d]*P+m[i][j];
        }
        hash t = 1;
        rep(i, p) t *= P;
        rep(i, h) {
            hash k = 0;
            rep(j, w) {
                k = k*P+f[i][j];
                if(j>=p) k -= t*f[i][j-p];
                hori[i][j] = k;
            }
        }
        hash tt = 1;
        rep(i, p) tt *= t;
        int ans = 0;
        for(int i=p-1; i<w; i++) {
            hash k = 0;
            rep(j, h) {
                k = k*t+hori[j][i];
                if(j>=p) k -= tt*hori[j-p][i];
                if(j>=p-1) rep(z, 8) if(hs[z]==k) { ans++; break; }
            }
        }
        printf("%d\n", ans);
    }
}
