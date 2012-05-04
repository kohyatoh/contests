#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (1000000007LL)

typedef vector<vector<Int> > mat;

mat mul(const mat& a, const mat& b) {
    const int n = a.size();
    mat r(n, vector<Int>(n, 0));
    rep (i, n) rep (j, n) {
        rep (k, n) r[i][j] = (r[i][j]+a[i][k]*b[k][j]) % MOD;
    }
    return r;
}

mat pow(mat a, Int x) {
    const int n = a.size();
    mat r(n, vector<Int>(n, 0));
    rep (i, n) r[i][i] = 1;
    rep (k, 64) {
        if (x & (1LL<<k)) {
            r = mul(r, a);
        }
        a = mul(a, a);
    }
    return r;
}

int main() {
    mat a(2, vector<Int>(2));
    a[0][0] = a[1][1] = 3;
    a[0][1] = a[1][0] = 1;
    Int x;
    cin >> x;
    a = pow(a, x);
    cout << a[0][0] << endl;
    return 0;
}
