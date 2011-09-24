#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

struct SA {
    static const int N = 200000; // len+1<=N
    int a[N], lcp[N];

    void build(const string& s) { build(s.c_str(), s.size()); }
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

struct Manacher {
    static const int N = 200000 * 2; // len*2
    int rad[N];
    void build(const string& s) { build(s.c_str(), s.size()); }
    void build(const char *t, int n) {
        int k;
        for(int i=0, j=0; i<2*n; i+=k, j=max(j-k, 0)) {
            while(i-j>=0 && i+j+1<2*n && t[(i-j)/2]==t[(i+j+1)/2]) j++;
            rad[i] = j;
            for(k=1; i-k>=0 && rad[i]-k>=0 && rad[i-k]!=rad[i]-k; k++) {
                rad[i+k] = min(rad[i-k], rad[i]-k);
            }
        }
    }
} mana;

struct BIT {
    static const int N = 80000;
    Int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void add(int k, Int a) { for(; k<N; k|=k+1) x[k]+=a; }
    Int sum(int k) { Int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
    Int rsum(int i, int j) { return i==0 ? sum(j) : sum(j)-sum(i-1); }
    Int esum(int i) { return rsum(i, N-1); }
} sum[2], cnt[2];

int of[200000];

int main() {
    string S, T;
    cin >> S >> T;
    const  string F(S+'$'+T);
    sa.build(F);
    mana.build(F);
    rep(i, F.size()+1) of[i] = sa.a[i] > (int)S.size();
    Int ans = 0;
    rep(odd, 2) {
        rep(i, 2) sum[i].init(), cnt[i].init();
        map<int, int> ex[2];
        for(int k=2; k<(int)F.size()+1; k++) {
            const int clen = sa.lcp[k];
            rep(i, 2) {
                map<int, int>::iterator it = ex[i].lower_bound(clen+1);
                while(it!=ex[i].end()) {
                    const int val = it->first, c = it->second;
                    sum[i].add(val, -(Int)val*c);
                    cnt[i].add(val, -c);
                    sum[i].add(clen, (Int)clen*c);
                    cnt[i].add(clen, c);
                    ex[i][clen] += c;
                    ex[i].erase(it++);
                }
            }
            const int vlen = odd ? mana.rad[sa.a[k]*2]/2+1 :
                                   sa.a[k] ? mana.rad[sa.a[k]*2-1]/2 : 0;
            ans += sum[1-of[k]].sum(vlen) + (Int)vlen*cnt[1-of[k]].esum(vlen+1);
            sum[of[k]].add(vlen, vlen);
            cnt[of[k]].add(vlen, 1);
            ex[of[k]][vlen]++;
        }
    }
    cout << ans << endl;
    return 0;
}
