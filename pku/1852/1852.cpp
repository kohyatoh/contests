#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int Q, len, n;

int main() {
    scanf("%d", &Q);
    rep(q, Q) {
        scanf("%d%d", &len, &n);
        int mn=0, mx=0;
        rep(i, n) {
            int pos;
            scanf("%d", &pos);
            mn = max(mn, min(pos, len-pos));
            mx = max(mx, max(pos, len-pos));
        }
        printf("%d %d\n", mn, mx);
    }
    return 0;
}
