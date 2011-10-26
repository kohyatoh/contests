#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k, a[2000000], b[2000000];

void build(int *a) {
    int x = 1;
    while(x*2<k) {
        rep(i, n-x+1) a[i] = min(a[i], a[i+x]);
        x *= 2;
    }
    rep(i, n-k+1) a[i] = min(a[i], a[i+k-x]);
}

int main() {
    scanf("%d%d", &n, &k);
    rep(i, n) {
        scanf("%d", a+i);
        b[i] = -a[i];
    }
    build(a);
    rep(i, n-k+1) printf("%d%c", a[i], i<n-k ? ' ' : '\n');
    build(b);
    rep(i, n-k+1) printf("%d%c", -b[i], i<n-k ? ' ' : '\n');
    return 0;
}
