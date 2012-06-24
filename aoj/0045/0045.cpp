#include <iostream>
using namespace std;
typedef long long Int;

int main() {
    char _;
    Int n = 0, m = 0, s = 0, x, y;
    while (cin >> x >> _ >> y) {
        s += x*y;
        n += y;
        m += 1;
    }
    cout << s << endl;
    cout << (Int)((double)n/m+0.5) << endl;
    return 0;
}
