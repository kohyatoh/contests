#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m, a[16], k, ev[16];
char id[200000];

int f(int x, bool ev) {
    if (ev) x *= 2;
    return x%10 + x/10;
}

int rec(int ix, int cur) {
    if (ix == k) return cur == 0;
    int ans = 0;
    rep (i, m) ans += rec(ix+1, (cur+f(a[i], ev[ix]))%10);
    return ans;
}

int main() {
    scanf("%d", &n);
    rep (i, n) scanf(" %c", id+i);
    scanf("%d", &m);
    rep (i, m) scanf("%d", a+i);
    sort(a, a+m);
    m = unique(a, a+m) - a;
    int base = 0;
    rep (i, n) {
        if (id[i] != '*') base = (base + f(id[i]-'0', (n-i-1)%2)) % 10;
        else ev[k++] = (n-i-1)%2;
    }
    printf("%d\n", rec(0, base));
    return 0;
}
