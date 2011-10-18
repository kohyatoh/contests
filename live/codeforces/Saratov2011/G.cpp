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

int N, T, a[200][2], b[200][2];
int M, c[200], d[200][200];
char name[200][32];
vector<int> have[200];

void simulate() {
    queue<int> q;
    rep(i, M) q.push(i);
    for(int ix=0; !q.empty(); ix=(ix+1)%(2*N)) {
        const int i = ix%N;
        const int u = ix<N ? 0 : 1;
        const int v = ix<N ? 1 : 0;
        int t = T;
        while(t>0 && !q.empty()) {
            const int k = q.front();
            q.pop();
            const int s = max(1, c[k]-d[i][k]-a[i][u]-b[i][v]);
            if(s<=t) have[i].push_back(k);
            else {
                q.push(k);
                d[i][k] += t;
                break;
            }
            t -= s;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &N, &T);
    rep(i, N) rep(j, 2) scanf("%d%d", a[i]+j, b[i]+j);
    scanf("%d", &M);
    rep(i, M) scanf("%s%d", name[i], c+i);
    simulate();
    rep(i, N) {
        printf("%u", have[i].size());
        rep(j, have[i].size()) printf(" %s", name[have[i][j]]);
        printf("\n");
    }
    return 0;
}

