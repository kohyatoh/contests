#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k, a[100000], t;
pair<int, int> v[100001];

int main() {
    for(;;) {
        scanf("%d%d", &n, &k);
        if(n==0 && k==0) return 0;
        rep(i, n) scanf("%d", a+i);
        v[0].first=v[0].second=0;
        rep(i, n) {
            v[i+1].first = v[i].first+a[i];
            v[i+1].second = i+1;
        }
        sort(v, v+n+1);
        while(k--) {
            scanf("%d", &t);
            int ans=abs(a[0]), ansu=1, ansv=1;
            for(int i=1, j=0; i<n+1; i++) {
                while(j<i) {
                    int s=abs(v[i].first-v[j].first);
                    if(abs(t-s)<abs(t-ans)) {
                        if(v[i].second<v[j].second) ans=s, ansu=v[i].second+1, ansv=v[j].second;
                        else ans=s, ansu=v[j].second+1, ansv=v[i].second;
                        if(ans==t) goto fin;
                    }
                    if(v[j].first>=v[i].first-t) break;
                    j++;
                }
            }
fin:
            printf("%d %d %d\n", ans, ansu, ansv);
        }
    }
}
