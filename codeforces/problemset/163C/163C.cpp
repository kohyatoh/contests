#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int n;
double L, v1, v2, a[100000], ans[100001];

int main() {
    scanf("%d%lf%lf%lf", &n, &L, &v1, &v2);
    rep (i, n) scanf("%lf", a+i);
    const double ml = (1 - v1/(v1+v2)) * L;
    vector<pair<double, int> > v;
    rep (i, n) {
        v.push_back(mp((2*L-a[i])/v1, i+1));
        if (a[i] < ml) v.push_back(mp((ml-a[i])/v1, -(i+1)));
        else v.push_back(mp((2*L-a[i]+ml)/v1, -(i+1)));
    }
    const double T = 2*L/v1;
    v.push_back(mp(T, 0));
    sort(v.begin(), v.end());
    int cnt = 0;
    rep (i, n) if (0 <= a[i] && a[i] < ml) cnt++;
    double t = 0;
    rep (i, v.size()) {
        const int k = v[i].second;
        const double nt = v[i].first;
        ans[cnt] += (nt-t) / T;
        t = nt;
        if (k > 0) cnt++;
        else if (k < 0) cnt--;
    }
    rep (i, n+1) printf("%.12f\n", ans[i]);
    return 0;
}
