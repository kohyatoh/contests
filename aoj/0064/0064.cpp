#include <iostream>
#include <sstream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

int main() {
    Int ans = 0;
    string s;
    while (getline(cin, s)) {
        rep (i, s.size()) if (!isdigit(s[i])) s[i] = ' ';
        istringstream sin(s);
        Int a;
        while (sin >> a) ans += a;
    }
    cout << ans << endl;
    return 0;
}
