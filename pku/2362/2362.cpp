#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
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
#include <functional>
#include <complex>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define ASS(a) (assert(a))
#define DBG(...) (fprintf(stderr,"%d: ",__LINE__)+fprintf(stderr,__VA_ARGS__))
#else
#define LOG(...) ((void)0)
#define ASS(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

int T, n, a[20], x, vis[1<<20];
vector<int> v;

void dfs(int b, int l) {
    if(vis[b] || l>x) return;
    vis[b] = 1;
    if(l==x) v.push_back(b);
    rep(i, n) if((b&(1<<i))==0) dfs(b|(1<<i), l+a[i]);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        rep(i, n) scanf("%d", a+i);
        v.clear();
        const int s = accumulate(a, a+n, 0);
        LOG(s);
        if(s%4==0) {
            x = s/4;
            memset(vis, 0, sizeof(vis));
            dfs(0, 0);
            sort(v.begin(), v.end());
        }
        LOG(v.size());
        bool yes = false;
        const int nn = 1<<n;
        rep(i, v.size()) {
            rep(j, i) if((v[i]&v[j])==0) {
                const int v1 = v[i]|v[j];
                rep(k, j) if((v1&v[k])==0) {
                    const int v2 = v1|v[k];
                    if(binary_search(v.begin(), v.end(), (nn-1)^v2)) {
                        yes = true;
                        goto end;
                    }
                }
            }
        }
end:
        printf("%s\n", yes ? "yes" : "no");
    }
    return 0;
}


