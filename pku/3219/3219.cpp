#include <iostream>
using namespace std;
typedef long long Int;

Int f(int n) {
    Int t=2, c=0;
    while(t<=n) {
        c += n/t;
        t *= 2;
    }
    return c;
}

int main() {
    Int n, k;
    while(cin >> n >> k) {
        cout << (f(n)==f(k)+f(n-k)) << endl;
    }
    return 0;
}

