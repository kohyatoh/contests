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
typedef long long Int;
#define INF MY_INFINITY

int n, m, cnt[300000], nxt[300000][128];
char s[128];

void rec(int cur, int level) {
    if(cnt[cur]) {
        s[level] = '\0';
        printf("%s %.4f\n", s, 100.0*cnt[cur]/n);
    }
    rep(i, 128) if(nxt[cur][i]) {
        s[level] = (char)i;
        rec(nxt[cur][i], level+1);
    }
}

int main() {
    n = 0;
    m = 1;
    while(gets(s)) {
        int cur=0;
        for(char *p=s; *p; p++) {
            if(nxt[cur][(int)*p]==0) nxt[cur][(int)*p]=m++;
            cur = nxt[cur][(int)*p];
        }
        LOG(cur);
        cnt[cur]++;
        n++;
    }
    memset(s, 0, sizeof(s));
    rec(0, 0);
    return 0;
}


