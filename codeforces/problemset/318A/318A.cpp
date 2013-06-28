#include <iostream>
using namespace std;
typedef long long Int;

int main() {
    Int n, k;
    cin >> n >> k;
    k--;
    const Int h = n-n/2;
    if (k < h) cout << k*2+1 << endl;
    else cout << (k-h)*2+2 << endl;
    return 0;
}
