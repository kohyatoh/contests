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
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

const int NN=50000;
int E, H, head[NN];
vector<int> from, to, next;
int vis[NN], cvis, mat[NN];
void init(int h) { E=0; H=h; memset(head, -1, sizeof(head)); }
void add_edge(int s, int t) {
    t += H;
    from.pb(s); to.pb(t); next.pb(head[s]);
    head[s]=E; E++;
}
bool rec(int at) {
    if(at<0) return true;
    for(int x=head[at]; x!=-1; x=next[x]) if(vis[to[x]]!=cvis) {
        vis[to[x]] = cvis;
        if(rec(mat[to[x]])) {
            mat[at] = to[x];
            mat[to[x]] = at;
            return true;
        }
    }
    return false;
}
int match() {
    memset(mat, -1, sizeof(mat));
    memset(vis, -1, sizeof(vis));
    int r=0;
    rep(i, H) {
        cvis = i;
        if(rec(i)) r++;
    }
    return r;
}

int bitcount(int a) {
    int c = 0;
    while(a) {
        a &= a-1;
        c++;
    }
    return c;
}

vector<string> make(const string& s) {
    const int n = s.size();
    vector<string> a;
    if(n<=4) a.push_back(s);
    else {
        const int nn = 1<<n;
        rep(b, nn) if(b>0 && bitcount(b)<=4) {
            string t;
            rep(i, n) if(b&(1<<i)) t+=s[i];
            a.push_back(t);
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<string> all;
    int n;
    char s[16];
    scanf("%d", &n);
    init(n);
    map<string, int> ids;
    rep(k, n) {
        scanf("%s", s);
        vector<string> ss(make(s));
        rep(i, ss.size()) {
            if(ids.count(ss[i])==0) {
                const int m = ids.size();
                all.push_back(ss[i]);
                ids[ss[i]] = m;
            }
            add_edge(k, ids[ss[i]]);
        }
    }
    if(match()<n) printf("%d\n", -1);
    else {
        rep(i, n) printf("%s\n", all[mat[i]-n].c_str());
    }
    return 0;
}

