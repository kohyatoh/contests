#include <stdio.h>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define INF (1<<30)
int n, x[1000], m;
pair<int, int> s[500000], z[500000];


int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d", x+i);
        m = 0;
        rep(i, n) rep(j, i) {
            s[m].first = x[i]+x[j];
            s[m].second = x[i];
            z[m].first = x[i]-x[j];
            z[m].second = x[i];
            m++;
        }
        sort(s, s+m, greater<pair<int, int> >());
        sort(z, z+m, greater<pair<int, int> >());
        int ans=-INF;
        for(int si=0, zi=0, zj=m-1; si<m; si++) {
            int a=s[si].second, b=s[si].first-a;
            while(zi<m && z[zi].first>s[si].first) zi++;
            if(zi<m && z[zi].first==s[si].first) {
                for(int i=zi; i<m && z[i].first==s[si].first; i++) {
                    int d=z[i].second, c=d-z[i].first;
                    if(a!=c && a!=d && b!=c && b!=d) {
                        ans=max(ans, d);
                        break;
                    }
                }
            }
            while(zj>=1 && -z[zj-1].first>=s[si].first) zj--;
            if(-z[zj].first==s[si].first) {
                for(int i=zj; i<m && -z[i].first==s[si].first; i++) {
                    int c=z[i].second, d=c-z[i].first;
                    if(a!=c && a!=d && b!=c && b!=d) {
                        ans=max(ans, d);
                        break;
                    }
                }
            }
        }
        if(ans==-INF) printf("no solution\n");
        else printf("%d\n", ans);
    }
}

