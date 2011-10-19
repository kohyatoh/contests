#include <iostream>
using namespace std;
typedef long long Int;

int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }

int solve(Int x) {
    int ans = 0;
    Int p = x>0 ? x : -x;
    for(Int k=2; k*k<=p; k++) if(p%k==0) {
        int c = 0;
        while(p%k==0) c++, p/=k;
        ans = gcd(ans, c);
    }
    if(p>1) return 1;
    if(x<0) while(ans%2==0) ans /= 2;
    return ans;
}

int main() {
    for(;;) {
        Int x;
        cin >> x;
        if(x==0) return 0;
        cout << solve(x) << endl;
    }
}
