#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

#define PMAX (10000000)
int pt[PMAX];
vector<int> primes;

void build_pt() {
    primes.push_back(2);
    for(int i=4; i<PMAX; i+=2) pt[i] = 2;
    for(int i=3; i<PMAX; i+=2) if(pt[i]==0) {
        primes.push_back(i);
        if(i < 10000) for(int j=i*i; j<PMAX; j+=i) pt[j] = i;
    }
}

vector<pair<Int, int> > factors(Int p) {
    vector<pair<Int, int> > rs;
    if(p<2) return rs;
    if(p<PMAX) {
        while(p>1) {
            const int k = pt[p]==0 ? p : pt[p];
            int c = 0;
            while(p%k==0) p/=k, c++;
            rs.push_back(mp(k, c));
        }
        sort(rs.begin(), rs.end());
    }
    else {
        rep(i, primes.size()) {
            const int k = primes[i];
            if((Int)k*k>p) break;
            if(p%k==0) {
                int c = 0;
                while(p%k==0) p/=k, c++;
                rs.push_back(mp(k, c));
            }
        }
        if(p>1) rs.push_back(mp(p, 1));
    }
    return rs;
}

int main() {
    build_pt();
    for (int _q = 0;; _q++) {
        Int n;
        cin >> n;
        if (n == 0) return 0;
        Int ans = 0;

        vector<pair<Int, int> > fs = factors(n);
        Int h = 1;
        rep (i, fs.size()) {
            const int k = (fs[i].second+1) / 2;
            rep (_, k) h *= fs[i].first;
        }
        ans = (n-1) / h * 2;

//        rep (i, n) if (i && i*i % n == 0) ans++;
//        ans *= 2;

//        rep (i, n) if (i > 0) rep (j, n) if (j > 0) {
//            const Int a = n*n+i*i;
//            const Int b = n*n+j*j;
//            const Int c = (n-i)*(n-i)+(n-j)*(n-j);
//            if (c+a == b || c+b == a) ans++;
//      }

        cout << "Case " << _q+1 << ": ";
        if (ans == 0) cout << "Impossible" << endl;
        else cout << ans*4 << endl;
    }
}
