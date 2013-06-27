#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long Int;

int main() {
    Int x, y, m;
    cin >> x >> y >> m;
    Int ans = 0;
    while (x < m && y < m) {
        if (x <= 0 && y <= 0) { ans = -1; break; }
        if (x < y) swap(x, y);
        if (y < 0) {
            ans += (-y+x-1) / x;
            y += (-y+x-1) / x * x;
        }
        else {
            ans++;
            y += x;
        }
    }
    cout << ans << endl;
    return 0;
}
