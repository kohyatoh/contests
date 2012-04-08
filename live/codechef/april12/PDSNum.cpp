#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

int a[11], c[11], m[11], gs[11][9000][16];
map<Int, Int> cat[11];
Int pre[11], fac[11], pow9[11], pow10[11];

Int encode(const vector<int>& x) {
    Int a = 0;
    rep (i, x.size()) a = a * 10 + x[i];
    return a;
}

Int zz(int n, int c[10]) {
    Int r = fac[n];
    rep (k, 10) r /= fac[c[k]];
    return r;
}

int sum(int a) {
    int s = 0;
    for (; a; a/=10) s += a%10;
    return s;
}

int pro(int a) {
    int s = 1;
    for (; a; a/=10) s *= a%10;
    return s;
}

void precat(int n, int k, vector<int>& x) {
    if (k == 10) {
        /*
        rep (i, x.size()) printf("%d ", x[i]);
        printf("\n");
        rep (i, 10) printf("%d ", c[i]);
        printf("\n");
        */
        cat[n][encode(x)] += zz(n-x.size(), c);
        return ;
    }
    precat(n, k+1, x);
    const int m = c[k];
    rep (i, m) {
        c[k]--;
        x.push_back(k);
        precat(n, k+1, x);
    }
    rep (i, m) {
        c[k]++;
        x.pop_back();
    }
}

void gen(int n, int k) {
    int p = 1, s = 0;
    rep (i, n) p *= a[i], s += a[i];
    if (s && p % s == 0) {
        rep (i, n) gs[n][m[n]][i] = a[i];
        m[n]++;
        memset(c, 0, sizeof(c));
        rep (i, n) c[a[i]]++;
        vector<int> x;
        precat(n, 1, x);
    }
    if (n < 10) for (int i = k; i < 10; i++) {
        a[n] = i;
        gen(n+1, i);
    }
}

Int count0(int x) {
    int n = 0;
    for (int p = x; p; p /= 10) a[n++] = p%10;
    Int ans = 0;
    ans += pow10[n-1];
    rep (i, n) ans -= pow9[i];
    bool zero = false;
    rep (k, n) {
        const int dig = a[n-1-k];
        const int rem = n-1-k;
        if (k) {
            ans += dig * pow10[rem];
            if (dig && !zero) ans -= (dig-1) * pow9[rem];
        }
        else if (dig) {
            ans += (dig-1) * pow10[rem];
            if (dig && !zero) ans -= (dig-1) * pow9[rem];
        }
        if (dig == 0) zero = true;
    }
    return ans;
}


Int f(int n, int z) {
    /*
    static int c[10];
    rep (i, 10) c[i] = 0;
    rep (i, n) c[gs[n][z][i]]++;
    */
    /*
    Int w = fac[n];
    rep (i, 10) w /= fac[c[i]];
    */
    Int ans = 0;
    vector<int> x;
    rep (k, n) {
        const int dig = a[n-1-k];
        for (int i = 1; i < dig; i++) {
            vector<int> y(x);
            y.push_back(i);
            sort(y.begin(), y.end());
            ans += cat[n][encode(y)];
        }
        if (dig == 0) break;
        x.push_back(dig);
    }
    /*
    rep (k, n) {
        const int dig = a[n-1-k];
        for (int i = 1; i < dig; i++) if (c[i]) {
            ans += w * c[i] / (n-k);
        }
        w *= c[dig];
        w /= (n-k);
        if (c[dig]-- == 0) break;
    }
    */
    return ans;
}

Int countr(int x) {
    int n = 0, p = x;
    while (p) {
        a[n++] = p%10;
        p /= 10;
    }
    Int ans = 0;
    rep (i, n) if (i) ans += pre[i];
//    rep (i, m[n]) ans += f(n, i);
     ans += f(n, 0);
//    printf("countr %d: %d\n", x, ans);
    return ans;
}

Int count(int x) {
    return count0(x) + countr(x);
}

int solve(int nth) {
    Int l = 1, r = 1500000000;
    while (r - l > 1) {
        const int mid = (l+r) / 2;
        if (count(mid) < nth) l = mid;
        else r = mid;
    }
    return l;
}

void check() {
    int k = 0;
    for (int i = 1; i < 10000; i++) if (pro(i) % sum(i) == 0) {
        k++;
        if (solve(k) != i) {
            printf("E! %d, dig %d\n", solve(k), i);
        }
    }
    printf("ok, %d\n", k);
}

int main() {
    fac[0] = 1;
    rep (i, 10) fac[i+1] = fac[i] * (i+1);
    pow9[0] = 1;
    rep (i, 10) pow9[i+1] = pow9[i] * 9;
    pow10[0] = 1;
    rep (i, 10) pow10[i+1] = pow10[i] * 10;
    gen(0, 1);
    rep (k, 11) rep (z, m[k]) {
        static int c[10];
        rep (i, 10) c[i] = 0;
        rep (i, k) c[gs[k][z][i]]++;
        pre[k] += zz(k, c);
    }
//    check();
    for (;;) {
        int nth;
        scanf("%d", &nth);
        if (nth == 0) return 0;
        printf("%d\n", solve(nth));
    }
    return 0;
}
