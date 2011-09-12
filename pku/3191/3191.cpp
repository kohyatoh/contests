#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[100];

int main() {
    long long n;
    cin >> n;
    int parity = n>0;
    if(n<0) n=-n;
    rep(i, 50) if(n&(1LL<<i)) {
        if(i%2==parity) n += 1LL<<i;
        a[i] = 1;
    }
    int ix = 50;
    while(ix>0 && a[ix]==0) ix--;
    while(ix>=0) cout << a[ix--];
    cout << endl;
    return 0;
}
