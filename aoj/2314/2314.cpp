#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
inline void update(int &a, int b) { if(a<b) a=b; }

int H, W;
char f[16][16];

void flip() {
    static char tmp[16][16];
    memcpy(tmp, f, sizeof(tmp));
    rep(i, H) rep(j, W) f[j][i] = tmp[i][j];
    swap(H, W);
}

int solve() {
    if(W==1 && H==1) return f[0][0]=='.' ? 0 : 1;
    if(W>H) flip();
    if(W==1) flip();
    map<vector<int>, int> dp[2];
    int cur = 0, nxt = 1;
    dp[cur][vector<int>()] = 0;
    rep(h, H) rep(k, W) {
        dp[nxt].clear();
        for(map<vector<int>, int>::iterator it=dp[cur].begin();
                it!=dp[cur].end(); ++it) {
            int z = 0;
            rep(i, it->first.size()) z |= it->first[i];
            if(f[h][k]=='.' || f[h][k]=='?') {
                // put white
                if((h==0 || z&(1<<k)) && (k==0 || z&(1<<(k-1)))) {
                    vector<int> v(it->first);
                    rep(i, v.size()) v[i] &= ~(1<<k);
                    sort(v.begin(), v.end());
                    if(v.empty() || v[0]!=0) update(dp[nxt][v], it->second);
                }
            }
            if(f[h][k]=='#' || f[h][k]=='?') {
                // put black
                if(k==0) {
                    vector<int> v(it->first);
                    if((z&(1<<k))==0) v.push_back(1<<k);
                    sort(v.begin(), v.end());
                    update(dp[nxt][v], it->second+1);
                }
                else {
                    const int t = (1<<k) + (1<<(k-1));
                    bool loop = false;
                    rep(i, it->first.size()) if((it->first[i]&t)==t) loop=true;
                    if(!loop) {
                        vector<int> v(it->first);
                        const int REMOVED = 1<<30;
                        int x = 1<<k;
                        rep(i, v.size()) if(v[i]&t) {
                            x |= v[i];
                            v[i] = REMOVED;
                        }
                        v.push_back(x);
                        sort(v.begin(), v.end());
                        while(v.size() && v.back()==REMOVED) v.pop_back();
                        update(dp[nxt][v], it->second+1);
                    }
                }
            }
        }
        swap(cur, nxt);
    }
    int ans = -1;
    for(map<vector<int>, int>::iterator it=dp[cur].begin();
            it!=dp[cur].end(); ++it) {
        if(it->first.size()==1) update(ans, it->second);
    }
    return ans;
}

int main() {
    scanf("%d%d", &H, &W);
    rep(i, H) rep(j, W) scanf(" %c", f[i]+j);
    printf("%d\n", solve());
    return 0;
}
