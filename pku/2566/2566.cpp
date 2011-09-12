#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k, a[100000], t;
int main() {
    for(;;) {
        scanf("%d%d", &n, &k);
        if(n==0 && k==0) return 0;
        rep(i, n) scanf("%d", a+i);
        int s=0;
        multimap<int, int> mm;
        rep(i, n) {
            s += a[i];
            mm.insert(make_pair(s, i));
        }
        while(k--) {
            scanf("%d", &t);
            s = 0;
            int ans=abs(a[0]), ansu=0, ansv=0;
            rep(i, n) {
                s += a[i];
                if(abs(t-abs(s))<abs(t-ans)) ans=abs(s), ansu=0, ansv=i;
                multimap<int, int>::iterator it = mm.lower_bound(s-t);
                while(it!=mm.begin() && (it==mm.end() || it->first>s-t || it->second==i)) it--;
                for(; it!=mm.end(); it++) {
                    if(it->second==i) continue;
                    if(abs(t-abs(s-it->first))<abs(t-ans)) {
                        if(it->second<i) ans=abs(s-it->first), ansu=it->second+1, ansv=i;
                        else ans=abs(s-it->first), ansu=i+1, ansv=it->second;
                    }
                    if(it->first>=s-t) break;
                }
            }
            printf("%d %d %d\n", ans, ansu+1, ansv+1);
        }
    }
}
