#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD (100000007LL)
typedef long long Int;

int c[10000001];

int main() {
    int n, a;
    scanf("%d", &n);
    rep (_, n) {
        scanf("%d", &a);
        c[a]++;
    }
    Int ans = 1;
    for (int i = 10000000; i > 0; i--) {
        ans += min(i*4, c[i]);
        c[i-1] += c[i];
    }
    cout << ans << endl;
    return 0;
}
