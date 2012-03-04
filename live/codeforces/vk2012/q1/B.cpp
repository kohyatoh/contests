#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, s[8];

int main() {
    scanf("%d", &n);
    rep (i, n) {
        int x;
        scanf("%d", &x);
        s[x]++;
    }
    int ans = 0;
    ans += s[4];
    ans += s[3];
    s[1] -= min(s[1], s[3]);
    const int r = s[1] + 2*s[2];
    ans += (r+3) / 4;
    printf("%d\n", ans);
    return 0;
}
