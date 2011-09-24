#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define MOD (100000007LL)
typedef long long Int;

Int extgcd(Int a, Int b, Int& x, Int& y) {
    Int g=a; x=1; y=0;
    if(b!=0) g=extgcd(b, a%b, y, x), y-=(a/b)*x;
    return g;
}

Int invMod(Int a, Int m) {
    Int x, y;
    if(extgcd(a, m, x, y)==1) return (x+m)%m;
    return 0;
}

Int rv[200];

int n, id[200], m, x[200];
double p[200], w[200];
vector<pair<double, double> > v[200];

void visit(int at, int ix) {
    if(x[at]!=-1) return ;
    x[at] = ix;
    visit(id[at], ix);
    v[ix].push_back(mp(p[at], w[at]));
}

double calc(int k, int st) {
    double a = 0;
    rep(i, v[k].size()) {
        if(i==st) a += 1/v[k][i].first;
        else a += 1/v[k][i].second;
    }
    return a;
}

int main() {
    rep(i, 200) if(i) rv[i] = invMod(i, MOD);
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%lf%d%lf", p+i, id+i, w+i);
        m = 0;
        memset(x, -1, sizeof(x));
        rep(i, 200) v[i].clear();
        rep(i, n) if(x[i]==-1) visit(i, m++);
        double anst = 0;
        Int ansn = 1;
        rep(i, n) ansn = ansn*(i+1)%MOD;
        rep(k, m) {
            double ex = 1e100;
            vector<double> xx;
            rep(i, v[k].size()) xx.push_back(calc(k, i));
            sort(xx.begin(), xx.end());
            anst += xx[0];
            int cnt = 0;
            while(cnt<(int)xx.size() && xx[0]==xx[cnt]) cnt++;
            rep(i, v[k].size()) ansn = ansn*rv[i+1]%MOD;
            ansn = ansn*cnt%MOD;
        }
        printf("%.12f %d\n", anst, (int)ansn);
    }
}

