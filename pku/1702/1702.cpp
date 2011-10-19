#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

Int x[20];

void put(const vector<Int>& v) {
    if(v.empty()) cout << "empty";
    else {
        rep(i, v.size()) {
            if(i) cout << ',';
            cout << v[i];
        }
    }
}

int main() {
    x[0] = 1;
    rep(i, 19) x[i+1] = x[i]*3;
    int T;
    cin >> T;
    while(T--) {
        Int a;
        cin >> a;
        rep(i, 20) a += x[i];
        vector<Int> l, r;
        rep(i, 20) {
            if(a%3==0) l.push_back(x[i]);
            if(a%3==2) r.push_back(x[i]);
            a /= 3;
        }
        put(l);
        cout << ' ';
        put(r);
        cout << endl;
    }
}
