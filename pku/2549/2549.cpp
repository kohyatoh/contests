#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct hashmap {
   // key -> id
   typedef int key_t;
   static const int range=1000009, N=1000000;
   int hn, head[range], next[N];
   key_t key[N];
   int hash(const key_t& k) { return abs(k)%range; }
   void init() { hn=0; memset(head, -1, sizeof(head)); }
   int index(const key_t& k) {
       int cur=head[hash(k)];
       while(cur!=-1 && key[cur]!=k) cur=next[cur];
       return cur;
   }
   int add(const key_t& k) {
       int hv=hash(k);
       key[hn]=k; next[hn]=head[hv]; head[hv]=hn;
       return hn++;
   }
   int get(const key_t& k) { int ix=index(k); return ix==-1?add(k):ix; }
   int size() { return hn; }
} hm;

#define INF (1<<30)
int n, x[1000], s[1000000], p[1000001], v[1000000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d", x+i);
        memset(s, 0, sizeof(s));
        sort(x, x+n);
        hm.init();
        rep(i, n) rep(j, n) if(i!=j) s[hm.get(x[i]+x[j])]++;
        rep(i, hm.size()) p[i+1]=p[i]+s[i];
        rep(i, n) rep(j, n) if(i!=j) {
            int ix=hm.index(x[i]+x[j]);
            v[p[ix]+--s[ix]] = x[i];
        }
        int ans=-INF;
        for(int i=n-1; i>=0; i--) rep(j, n) if(i!=j) {
            int ix=hm.index(x[i]-x[j]);
            if(ix==-1) continue;
            for(int k=0; p[ix]+k<p[ix+1]; k++) {
                int a=v[p[ix]+k], b=x[i]-a-x[j];
                if(x[i]!=a && x[i]!=b && x[j]!=a && x[j]!=b) {
                    ans = x[i];
                    goto fin;
                }
            }
        }
fin:
        if(ans==-INF) printf("no solution\n");
        else printf("%d\n", ans);
    }
}

