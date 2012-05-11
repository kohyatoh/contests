#include <iostream>
using namespace std;
typedef long long Int;

Int powmod(Int a, Int x, Int mod) {
    if (x == 0) return a == 0 ? 0 : 1%mod;
    if (x % 2) return a*powmod(a, x-1, mod)%mod;
    return powmod(a*a%mod, x/2, mod);
}

Int invmodp(Int a, Int mod) { return powmod(a, mod-2, mod); }

Int calc(Int k, Int l, Int r, Int p) {
    if (p == 2) return 1 - k % 2;
    const Int x = powmod(k%p, powmod(2, l, p-1), p);
    if (x == 1) {
        if (k % 2) return 2;
        else return powmod(2, r-l+1, p);
    }
    else {
        const Int y = (powmod(x, powmod(2, r-l+1, p-1), p)-1+p) % p;
        const Int z = y * invmodp((x-1+p)%p, p) % p;
        if (k % 2) {
            const Int g = powmod(2, r-l, p);
            return z * invmodp(g, p) % p;
        }
        return z;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Int k, l, r, p;
        cin >> k >> l >> r >> p;
        cout << calc(k, l, r, p) << endl;
    }
    return 0;
}
