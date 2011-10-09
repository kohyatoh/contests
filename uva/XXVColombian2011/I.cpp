#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
inline void cmin(int &a, int b) { if(a>b) a = b; }

int N, R, r[20000], t[20000];
int cnt[256][400], sum[256][400];

int f(int x1, int y1, int x2, int y2) {
    return sum[x2][y2]-sum[x2][y1]-sum[x1][y2]+sum[x1][y1];
}

int build() {
    memset(cnt, 0, sizeof(cnt));
    rep(i, N) cnt[r[i]][t[i]]++;
    memset(sum, 0, sizeof(sum));
    rep(i, 200) rep(j, 380) {
        sum[i+1][j+1] = cnt[i][j]-sum[i][j]+sum[i+1][j]+sum[i][j+1];
    }
}

int calc(int b, int h, int l, int r) {
    if(r<360) return f(b, l, h+1, r+1);
    else return f(b, l, h+1, 360)+f(b, 0, h+1, r%360+1);
}

int solve(int H, int A) {
    int ans = 0;
    rep(i, 360) rep(h, R) ans = max(ans, calc(h, h+H-1, i, i+A));
    return ans;
}

int main() {
    for(;;) {
        scanf("%d%d", &N, &R);
        if(N==0 && R==0) return 0;
        rep(i, N) scanf("%d%d", r+i, t+i);
        build();
        int E;
        scanf("%d", &E);
        rep(_, E) {
            int H, A;
            scanf("%d%d", &H, &A);
            printf("%d\n", solve(H, A));
        }
    }
}


