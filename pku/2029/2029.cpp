#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, w, h, s, t, x[500], y[500];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        scanf("%d%d", &w, &h);
        rep(i, n) scanf("%d%d", x+i, y+i);
        scanf("%d%d", &s, &t);
        int ans=1;
        rep(i, n) rep(j, i) {
            if(abs(x[i]-x[j])>=s || abs(y[i]-y[j])>=t) continue;
            int sx=min(x[i], x[j]), sy=min(y[i], y[j]);
            int c=0;
            rep(k, n) {
                int dx=x[k]-sx, dy=y[k]-sy;
                if(0<=dx && dx<s && 0<=dy && dy<t) c++;
            }
            ans = max(ans, c);
        }
        printf("%d\n", ans);
    }
}
