#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, f[100], g[100];

int main() {
    for(;;) {
        scanf(" %d", &n);
        if(n==0) return 0;
        scanf("%d", &m);
        rep(i, n) scanf("%d", f+i);
        rep(i, m) scanf("%d", g+i);
        vector<double> a;
        rep(i, n) rep(j, m) a.push_back((double)f[i]/g[j]);
        sort(a.begin(), a.end());
        double ans = 0;
        rep(i, a.size()-1) ans = max(ans, a[i+1]/a[i]);
        printf("%.2f\n", ans);
    }
}
