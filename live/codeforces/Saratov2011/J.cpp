#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define pb push_back
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
typedef pair<int, int> P;
#define INF (1<<28)
#define MOD (YOUR_MODULUS)
inline double sq(double a) { return a*a; }

int n, type[200000];
P ps[200000];

double norm(int i, int j) {
    return sq(ps[i].first-ps[j].first)+sq(ps[i].second-ps[j].second);
}

int S[200000];

pair<int, int> closestPair() {
    vector<pair<P, int> > vs;
    rep(i, n) vs.push_back(mp(ps[i], i));
    sort(vs.begin(), vs.end());

    int s = 0, t = 1, m = 2;
    S[0] = 0; S[1] = 1;
    double d = norm(vs[s].second, vs[t].second);
    for(int i=2; i<n; S[m++] = i++) rep(j, m) {
        if(norm(vs[S[j]].second, vs[i].second)<d) {
            s = S[j];
            t = i;
            d = norm(vs[s].second, vs[t].second);
        }
        if(vs[S[j]].first.first < vs[i].first.first-d) S[j--] = S[--m];
    }
    return mp(vs[s].second, vs[t].second);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    rep(i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        ps[i] = P(abs(x), abs(y));
        if(x>=0 && y>=0) type[i] = 0;
        else if(x<=0 && y>=0) type[i] = 1;
        else if(x>=0 && y<=0) type[i] = 2;
        else if(x<=0 && y<=0) type[i] = 3;
    }
    pair<int, int> ans = closestPair();
    const int ix = ans.first, jx = ans.second;
    printf("%d %d %d %d\n", ix+1, type[ix]+1, jx+1, (3-type[jx])+1);
    return 0;
}

