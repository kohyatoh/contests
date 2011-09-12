#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, n, w[1010];

int main() {
    scanf("%d", &T);
    rep(q, T) {
        scanf("%d", &n);
        rep(i, n) scanf("%d", w+i);
        sort(w, w+n, greater<int>());
        int ans=0;
        rep(i, n) ans=max(ans, w[i]*(i+1));
        printf("%d\n", ans);
    }
    return 0;
}

