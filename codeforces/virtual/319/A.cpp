#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD (1000000007LL)
typedef long long Int;

char a[128];
Int p[1000];

int main() {
    p[0] = 1;
    rep (i, 1000-1) p[i+1] = p[i]*2%MOD;
    scanf("%s", a);
    int n = strlen(a);
    Int ans = 0;
    rep (i, n) if (a[i] == '1') {
        const int m = n-1-i;
        ans = (ans + p[i] * p[m*2] % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}
