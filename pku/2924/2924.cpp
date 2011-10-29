#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int main() {
    int T;
    cin >> T;
    rep(_q, T) {
        Int n, m;
        cin >> n >> m;
        cout << "Scenario #" << _q+1 << ":" << endl;
        cout << (n+m)*(m-n+1)/2 << endl;
        cout << endl;
    }
}
