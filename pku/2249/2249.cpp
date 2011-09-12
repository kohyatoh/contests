#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

typedef long long Int;

Int C(int n, int k) {
    if(n<k) return 0;
    k = min(k, n-k);
    Int r=1;
    rep(i, k) r=r*(n-i)/(i+1);
    return r;
}

int main() {
    for(;;) {
        int n, k;
        cin >> n >> k;
        if(n==0 && k==0) return 0;
        cout << C(n, k) << endl;
    }
    return 0;
}
