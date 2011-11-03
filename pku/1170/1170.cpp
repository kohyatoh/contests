#include <stdio.h>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
inline void cmin(int &a, int b) { if(a>b) a = b; }

int n, m, tg[8], rp[8];
int df[200][8], p[200];
int dp[7776], a[5];

int pack(int *a) {
    int sig = 0;
    rep(i, n) sig = sig*6+a[n-1-i];
    return sig;
}

void unpack(int sig, int *a) {
    rep(i, n) {
        a[i] = sig%6;
        sig /= 6;
    }
}

int main() {
    map<int, int> of;
    scanf("%d", &n);
    rep(i, n) {
        int c;
        scanf("%d%d%d", &c, tg+i, rp+i);
        of[c] = i;
    }
    scanf("%d", &m);
    rep(i, m) {
        int T;
        scanf("%d", &T);
        while(T--) {
            int c, k;
            scanf("%d%d", &c, &k);
            df[i][of[c]] += k;
        }
        scanf("%d", p+i);
    }
    int nn = 1;
    rep(i, n) nn *= 6;
    rep(b, nn) {
        unpack(b, a);
        rep(i, n) dp[b] += a[i]*rp[i];
    }
    rep(b, nn) {
        rep(k, m) {
            unpack(b, a);
            bool ok = true;
            rep(i, n) {
                a[i] += df[k][i];
                if(a[i]>tg[i]) ok = false;
            }
            if(!ok) continue;
            int sig = pack(a);
            cmin(dp[sig], dp[b]+p[k]);
        }
    }
    printf("%d\n", dp[pack(tg)]);
    return 0;
}
