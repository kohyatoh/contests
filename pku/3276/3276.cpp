#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)

int n, a[5000], s[6000];
char f[5000];

int calc(int k) {
    rep(i, n) a[i] = f[i]=='B';
    s[0] = 0;
    int ans = 0;
    rep(i, n) {
        int t = s[i];
        if(i-k>=0) t -= s[i-k];
        s[i+1] = s[i];
        if((t+a[i])%2) {
            if(i+k>=n) return INF;
            ans++;
            s[i+1]++;
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    rep(i, n) scanf(" %c", f+i);
    int ans=-1, minv=INF;
    rep(k, n) {
        const int v = calc(k);
        if(minv>v) ans=k+1, minv=v;
    }
    printf("%d %d\n", ans, minv);
    return 0;
}
