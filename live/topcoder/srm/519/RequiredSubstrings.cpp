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
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (1000000009LL)

struct node {
    int a[6];
};

int n, tbl[10][64][128];

bool operator<(const node& l, const node& r) {
    rep(i, n) if(l.a[i]!=r.a[i]) return l.a[i]<r.a[i];
    return false;
}

class RequiredSubstrings {
    public:
    int solve(vector <string> words, int C, int L) {
        n = words.size();
        memset(tbl, 0, sizeof(tbl));
        rep(i, n) rep(j, words[i].size()) {
            string sub(words[i].substr(0, j));
            for(char c='a'; c<='z'; c++) {
                string t(sub+c);
                rep(k, t.size()) {
                    if(t.substr(k)==words[i].substr(0, t.size()-k)) {
                        tbl[i][j][(int)c] = t.size()-k;
                        break;
                    }
                }
            }
        }
        LOG( tbl[0][0]['a'] );
        LOG( tbl[0][0]['b'] );
        LOG( tbl[1][1]['a'] );
        map<node, Int> dp[2];
        int cur = 0, nxt = 1;
        node src;
        rep(i, n) src.a[i] = 0;
        dp[cur][src] = 1;
        rep(_, L) {
            dp[nxt].clear();
            foreach(it, dp[cur]) {
                for(char c='a'; c<='z'; c++) {
                    node b(it->first);
                    rep(i, n) if(b.a[i]<(int)words[i].size()) {
                        b.a[i] = tbl[i][b.a[i]][(int)c];
                    }
                    dp[nxt][b] = (dp[nxt][b]+it->second)%MOD;
                }
            }
            swap(cur, nxt);
        }
        Int ans = 0;
        foreach(it, dp[cur]) {
            int c = 0;
            rep(i, n) if(it->first.a[i]==(int)words[i].size()) c++;
            if(c==C) ans = (ans+it->second)%MOD;
        }
        return ans;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
