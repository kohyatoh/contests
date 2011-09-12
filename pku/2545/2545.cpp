#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

unsigned long long p1, p2, p3, n;
unsigned long long q1, q2, q3;
double d1, d2, d3;

int main() {
    int p1, p2, p3, n;
    cin >> p1 >> p2 >> p3 >> n;
    q1=1; d1=1;
    vector<long long> v;
    rep(i, 80) {
        if(d1>1e18) break;
        q2=1; d2=1;
        rep(j, 80) {
            if(d1*d2>1e18) break;
            q3=1; d3=1;
            rep(k, 80) {
                if(d1*d2*d3>1e18) break;
                v.push_back(q1*q2*q3);
                q3*=p3; d3*=p3;
            }
            q2*=p2; d2*=p2;
        }
        q1*=p1; d1*=p1;
    }
    sort(v.begin(), v.end());
    cout << v[n] << endl;
    return 0;
}

