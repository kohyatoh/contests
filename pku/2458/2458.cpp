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
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF MY_INFINITY

char f[8][8], v[8][8];

int kount(int x, int y) {
    if(v[x][y]) return 0;
    v[x][y] = 1;
    int ans = 1;
    ans += kount(x+1, y);
    ans += kount(x-1, y);
    ans += kount(x, y+1);
    ans += kount(x, y-1);
    return ans;
}

bool isvalid() {
    rep(i, 5) rep(j, 5) if(v[i+1][j+1]==0) return kount(i+1, j+1)==7;
    return false;
}

int main() {
    vector<int> r;
    int b = (1<<7)-1;
    while(b<(1<<16)) {
        memset(v, -1, sizeof(v));
        rep(i, 4) rep(j, 4) if(b&(1<<(i*4+j))) v[i+1][j+1] = 0;
        if(isvalid()) {
            int to = 0;
            rep(i, 4) rep(j, 4) if(b&(1<<(i*4+j))) to |= 1<<(i*5+j);
            r.push_back(to);
            r.push_back(to<<1);
            r.push_back(to<<5);
            r.push_back(to<<6);
        }
        const int x=b&-b, y=b+x;
        b = ((b&~y)/x>>1)|y;
    }
    b = (1<<7)-1;
    while(b<(1<<15)) {
        memset(v, -1, sizeof(v));
        rep(i, 5) rep(j, 3) if(b&(1<<(i*3+j))) v[i+1][j+1] = 0;
        if(isvalid()) {
            int to = 0;
            rep(i, 5) rep(j, 3) if(b&(1<<(i*3+j))) to |= 1<<(i*5+j);
            r.push_back(to);
            r.push_back(to<<1);
            r.push_back(to<<2);
        }
        memset(v, -1, sizeof(v));
        rep(i, 3) rep(j, 5) if(b&(1<<(i*5+j))) v[i+1][j+1] = 0;
        if(isvalid()) {
            r.push_back(b);
            r.push_back(b<<5);
            r.push_back(b<<10);
        }
        const int x=b&-b, y=b+x;
        b = ((b&~y)/x>>1)|y;
    }
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    LOG(r.size());
    rep(i, 5) rep(j, 5) scanf(" %c", f[i]+j);
    int ans = 0;
    rep(k, r.size()) {
        int c = 0;
        rep(i, 25) if(r[k]&(1<<i)) {
            if(f[i/5][i%5]=='J') c++;
        }
        if(c>=4) ans++;
    }
    printf("%d\n", ans);
    return 0;
}


