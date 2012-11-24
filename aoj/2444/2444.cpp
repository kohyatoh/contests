#include <stdio.h>
#include <set>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;
#define P (31LL)
#define MOD1 (1000000009LL)
#define INV1 (838709685LL)
#define MOD2 (1000000007LL)
#define INV2 (129032259LL)

int n, m, a[400000];
Int B1[400000], B2[400000];
char s[400000], op[10];

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    rep (i, n) a[i] = s[i]-'a'+1;
    B1[0] = 1;
    rep (i, n) B1[i+1] = B1[i]*P % MOD1;
    B2[0] = 1;
    rep (i, n) B2[i+1] = B2[i]*P % MOD2;
    set<pair<Int, Int> > st;
    int L = 0, R = 0;
    Int cur1 = a[0], cur2 = a[0];
    rep (_, m) {
        scanf("%s", op);
        if (op[0] == 'L') {
            if (op[1] == '+') {
                cur1 = (cur1 - a[L]*B1[R-L]%MOD1 + MOD1) % MOD1;
                cur2 = (cur2 - a[L]*B2[R-L]%MOD2 + MOD2) % MOD2;
                L++;
            }
            else {
                cur1 = (cur1 + a[L-1]*B1[R-L+1]%MOD1) % MOD1;
                cur2 = (cur2 + a[L-1]*B2[R-L+1]%MOD2) % MOD2;
                L--;
            }
        }
        else {
            if (op[1] == '+') {
                cur1 = (cur1 * P + a[R+1]) % MOD1;
                cur2 = (cur2 * P + a[R+1]) % MOD2;
                R++;
            }
            else {
                cur1 = ((cur1 - a[R] + MOD1) % MOD1 * INV1) % MOD1;
                cur2 = ((cur2 - a[R] + MOD2) % MOD2 * INV2) % MOD2;
                R--;
            }
        }
        st.insert(make_pair(cur1, cur2));
    }
    printf("%d\n", (int)st.size());
    return 0;
}
