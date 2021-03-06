#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
typedef long long Int;

#define PMAX (65536)
int pt[PMAX];
vector<int> primes;

void build_pt() {
    primes.push_back(2);
    for(int i=4; i<PMAX; i+=2) pt[i] = 2;
    for(int i=3; i<PMAX; i+=2) if(pt[i]==0) {
        primes.push_back(i);
        for(int j=i+i; j<PMAX; j+=i) pt[j] = i;
    }
}

vector<pair<int, int> > factors(int p) {
    vector<pair<int, int> > rs;
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
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        int n;
        scanf("%d", &n);
        vector<pair<int, int> > fs(factors(n));
        int ans = 1;
        rep(i, fs.size()) ans *= fs[i].second*2+1;
        printf("Scenario #%d:\n", _q+1);
        printf("%d\n", (ans+1)/2);
        printf("\n");
    }
    return 0;
}
