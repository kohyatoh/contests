#include <stdio.h>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

pair<int, int> w[10], t[10];

int main() {
    rep(i, 6) scanf("%d%d", &w[i].first, &w[i].second);
    rep(i, 6) if(w[i].first>w[i].second) swap(w[i].first, w[i].second);
    map<pair<int, int>, int> m;
    rep(i, 6) m[w[i]]++;
    bool ans=false;
    rep(i, 5) rep(D, 2) {
        if(w[i].first==w[5].first) {
            t[0]=w[5];
            t[1]=w[i];
            t[2]=make_pair(w[5].second, w[i].second);
            rep(k, 3) if(t[k].first>t[k].second) swap(t[k].first, t[k].second);
            rep(k, 3) m[t[k]]-=2;
            bool f=true;
            rep(k, 3) if(m[t[k]]<0) f=false;
            if(f) ans=true;
            rep(k, 3) m[t[k]]+=2;
        }
        swap(w[i].first, w[i].second);
    }
    printf("%s\n", ans?"POSSIBLE":"IMPOSSIBLE");
    return 0;
}

