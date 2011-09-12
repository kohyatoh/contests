#include <stdio.h>
#include <string.h>
#include <algorithm>

#define N (500000)

struct hashmap {
    // key -> id
    typedef long long key_t;
    static const int range = 1000009;
    int hn, head[range], next[N];
    key_t key[N];
    int hash(const key_t& k) { return k%range; }
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

struct unionset {
    int ud[N];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} un;

char a[80], b[80];
int n, cnt[N];

long long tol(const char *a) {
    long long r=0;
    while(*a) r=r*30+*a++-'a'+1;
    return r;
}

int main() {
    hm.init();
    un.init();
    while(scanf("%s %s", a, b)!=EOF) {
        n++;
        int ax=hm.get(tol(a)), bx=hm.get(tol(b));
        un.set(ax, bx);
        cnt[ax]++, cnt[bx]++;
    }
    int t=0;
    for(int i=0; i<hm.size(); i++) if(cnt[i]%2) t++;
    puts(n==0 || (un.size(0)==hm.size() && (t==0 || t==2)) ? "Possible" : "Impossible");
    return 0;
}
