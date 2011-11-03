#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[4000], of[4000], r[4000];

int main() {
    scanf("%d", &n);
    int k1 = 0, k2 = 0;
    rep(i, n) {
        scanf("%d", a+i);
        if(a[i]==0) k2++;
    }
    rep(i, n) of[i] = a[i]==0 ? k1++ : k2++;
    for(int i=n-1, cur=0; i>=0; i--, cur=of[cur]) r[i] = a[cur];
    rep(i, n) printf("%d%c", r[i], i<n-1 ? ' ' : '\n');
    return 0;
}
