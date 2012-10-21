#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD (1000000007)
typedef long long Int;

#define N (5000010)
bool pt[N];
int ans[N];

int main() {
    for (int i = 4; i < N; i += 2) pt[i] = 1;
    for (int i = 3; i < N; i += 2) if (pt[i] == 0) {
        if ((Int)i*i < N) for (int j = i*i; j < N; j += i) pt[j] = 1;
    }
    ans[0] = 1;
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (pt[i] == 0) cnt++;
        ans[i] = (Int)ans[i-1] * cnt % MOD;
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", (int)ans[n]);
    }
    return 0;
}
