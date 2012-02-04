#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;
#define M (2300000)
#define MOD (500009LL)

bool np[M];
int cnt[M], sum[1000], ans[M];
vector<int> ps;

void rec(int a, int ix, int c) {
    Int r = a*(Int)ps[ix];
    for (int i = 2; r < M; i++, r *= ps[ix]) {
        cnt[r] = c*i;
        for (int k = ix+1; k < (int)ps.size() && r*ps[k] < M; k++) {
            rec(r, k, c*i);
        }
    }
}

int main() {
    const int lim = sqrt(M)+5;
    for (int i = 3; i < lim; i+=2) if (!np[i]) {
        for (int j = i*i; j < M; j+=i) np[j] = true;
    }
    ps.push_back(2);
    for (int i = 3; i < M; i+=2) if (!np[i]) ps.push_back(i);
    rep (i, ps.size()) rec(1, i, 1);
    ans[1] = 1;
    for (int i = 2; i < M; i++) {
        sum[cnt[i]]++;
        ans[i] = (Int)ans[i-1]*sum[cnt[i]] % MOD;
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        const int a = n < M ? ans[n] : 0;
        printf("%d\n", (int)((a+MOD-1)%MOD));
    }
    return 0;
}
