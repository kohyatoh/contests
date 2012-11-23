#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long Int;

string tos(Int k) {
    ostringstream o;
    o << k;
    return o.str();
}

Int ct(Int k, int d) {
    if (k == 0) return 0;
    return (k-1)/d;
}

Int dig(Int k, int d) {
    Int s = 0;
    for (Int a = 1, w = 1; a < k; a*=10, w++) {
        s += w*(ct(min(a*10, k), d)-ct(a, d));
    }
    return s;
}

Int f(Int k) {
    Int ans = dig(k, 1);
    ans -= dig(k, 3) + dig(k, 5);
    ans += dig(k, 15);
    ans += 4 * (ct(k, 3) + ct(k, 5));
    return ans;
}

int main() {
    Int n;
    cin >> n;
    Int r = 1;
    while (f(r) < n) r*=2;
    Int l = 0;
    while (r-l > 1) {
        const Int mid = (l+r)/2;
        if (f(mid) < n) l = mid; else r = mid;
    }
    const Int b = f(l);
    string s;
    for (Int k = l; b + s.size() < n+30; k++) {
        if (k%3 && k%5) s += tos(k);
        else {
            if (k%3 == 0) s += "Fizz";
            if (k%5 == 0) s += "Buzz";
        }
    }
    cout << s.substr(n-1-b, 20) << endl;
    return 0;
}
