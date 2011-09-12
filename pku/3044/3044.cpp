#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, w, m, q[100000];

int main() {
    scanf("%d%d", &n, &w);
    int ans = 0;
    q[m++] = 0;
    rep(_, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        while(q[m-1]>y) m--, ans++;
        if(q[m-1]<y) q[m++] = y;
    }
    ans += m-1;
    printf("%d\n", ans);
    return 0;
}
