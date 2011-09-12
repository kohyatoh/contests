#include <stdio.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, n, v[100];

int main() {
    rep(i, 100) v[i]=i*i;
    scanf("%d", &T);
    rep(q, T) {
        scanf("%d", &n);
        printf("%d\n", std::upper_bound(v, v+100, n)-1-v);
    }
    return 0;
}
