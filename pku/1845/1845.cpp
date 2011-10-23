#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define mp make_pair
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

vector<pair<int, int> > factors(int n) {
    vector<pair<int, int> > ps;
    int p = n;
    for(int i=2; (Int)i*i<=p; i++) if(p%i==0) {
        int c = 0;
        while(p%i==0) p/=i, c++;
        ps.push_back(mp(i, c));
    }
    if(p>1) ps.push_back(mp(p, 1));
    return ps;
}

// a^x mod m
Int modpow(Int a, Int x, Int m) {
    if(x==0) return 1;
    return x%2 ? a*modpow(a, x-1, m)%m : modpow(a*a%m, x/2, m);
}

// 1 + a + ... + a^x mod m
Int modgeo(Int a, Int x, Int m) {
    if(x==0) return 1;
    if(x%2==0) return (1+a*modgeo(a, x-1, m))%m;
    else {
        const Int t = modgeo(a, x/2, m);
        return (t+t*modpow(a, x/2+1, m))%m;
    }
}

#define MOD (9901)

int solve(int A, int B) {
    if(A==0) return 0;
    if(B==0) return 1;
    vector<pair<int, int> > ps(factors(A));
    int ans = 1;
    rep(i, ps.size()) {
        const Int p = ps[i].first, c = ps[i].second;
        ans = ans*modgeo(p, c*B, MOD)%MOD;
    }
    return ans;
}

int main() {
    int A, B;
    scanf("%d%d", &A, &B);
    printf("%d\n", solve(A, B));
    return 0;
}
