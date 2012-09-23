#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m, need[100], cnt[100];
char buf[100];

int solve() {
    int ans = 0;
    rep (i, 100) if (need[i]) {
        if (cnt[i] == 0) return -1;
        ans = max(ans, (need[i]+cnt[i]-1) / cnt[i]);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    scanf(" %s", buf);
    rep (i, n) need[buf[i]-'A']++;
    scanf(" %s", buf);
    rep (i, m) cnt[buf[i]-'A']++;
    printf("%d\n", solve());
    return 0;
}
