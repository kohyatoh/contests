#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

int n, a[200000];
Int k;

int main() {
    cin >> n >> k;
    rep (i, n) cin >> a[i];
    sort(a, a+n);
    k--;
    const int p = a[k/n];
    int c = 0, f = -1;
    rep (i, n) if (a[i] == p) {
        c++;
        if (f == -1) f = i;
    }
    const int q = a[(k-(Int)f*n) / c];
    printf("%d %d\n", p, q);
    return 0;
}
