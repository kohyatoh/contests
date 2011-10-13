#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct SA {
    static const int N = 200000; // len+1<=N
    int a[N], lcp[N];

    void build(const char *t, int n) {
        // saffix array
        static int g[N], b[N];
        rep(i, n+1) a[i]=i, g[i]=t[i];
        b[0] = b[n] = 0;
        sort(a, a+n+1, SAComp(0, g));
        for(int h=1; b[n]!=n; h*=2) {
            SAComp comp(h, g);
            sort(a, a+n+1, comp);
            rep(i, n) b[i+1] = b[i] + comp(a[i], a[i+1]);
            rep(i, n+1) g[a[i]] = b[i];
        }
        // longest common prefix (you can omit here)
        rep(i, n+1) b[a[i]] = i;
        int h = 0;
        rep(i, n) {
            const int j = a[b[i]-1];
            while(j+h<n && i+h<n && t[j+h]==t[i+h]) h++;
            lcp[b[i]] = h;
            if(h) h--;
        }
        lcp[0] = -1;
    }

    struct SAComp {
        const int h, *g;
        SAComp(int h, int* g) : h(h), g(g) {}
        bool operator()(int l, int r) {
            return g[l]!=g[r] ? g[l]<g[r] : g[l+h]<g[r+h];
        }
    };
} sa;

char s[50000];

int main() {
    gets(s);
    int T = atoi(s);
    while(T--) {
        gets(s);
        const int n = strlen(s);
        rep(i, n) s[n+i] = s[i];
        s[n+n] = 0;
        sa.build(s, 2*n);
        int ix = -1;
        rep(i, 2*n+1) if(sa.a[i]<n) {
            ix = i;
            break;
        }
        int ans = sa.a[ix];
        for(int i=ix+1; i<=2*n && sa.lcp[i]>=n; i++) ans = min(ans, sa.a[i]);
        printf("%d\n", ans+1);
    }
    return 0;
}
