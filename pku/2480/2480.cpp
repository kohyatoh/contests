#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

vector<int> factors(int m) {
    vector<int> ps;
    int p = m;
    for(Int i=2; i*i<=p; i++) if(p%i==0) {
        ps.push_back(i);
        while(p%i==0) p/=i;
    }
    if(p>1) ps.push_back(p);
    return ps;
}

int phi(const vector<int>& ps, int n) {
    int a = n;
    rep(i, ps.size()) if(n%ps[i]==0) a -= a/ps[i];
    return a;
}

int N;
vector<int> ps;

Int f(int x) {
    return (Int)x*phi(ps, N/x);
}

Int rec(int ix, Int x) {
    if((int)ps.size()==ix) return f(x);
    Int ans = 0;
    do {
        ans += rec(ix+1, x);
        x *= ps[ix];
    } while(N%x==0);
    return ans;
}

int main() {
    while(scanf("%d", &N)!=EOF) {
        ps = factors(N);
        cout << rec(0, 1) << endl;
    }
}
