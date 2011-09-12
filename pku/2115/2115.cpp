#include <iostream>
using namespace std;

typedef long long Int;
Int extgcd(Int a, Int b, Int& x, Int& y) {
    Int g=a; x=1; y=0;
    if(b!=0) g=extgcd(b, a%b, y, x), y-=(a/b)*x;
    return g;
}

// solve ax=b mod m
Int modeq(Int a, Int b, Int m) {
    Int x, y, g=extgcd(a, m, x, y);
    if(b%g>0) return -1; // unsolvable
    while(x<0) x+=m;
    return b/g*x%(m/g);
}

Int A, B, C, k;

int main() {
    for(;;) {
        cin >> A >> B >> C >> k;
        if(k==0) return 0;
        Int m=1LL<<k;
        A%=m, B%=m, C%=m;
        Int ans=modeq(C, (B-A+m)%m, m);
        if(ans!=-1) cout << ans << endl;
        else cout << "FOREVER" << endl;
    }
}

