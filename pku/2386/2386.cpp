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

char f[128][128];

void draw(int x, int y) {
    if(f[x][y]=='.') return;
    f[x][y] = '.';
    rep(i, 3) rep(j, 3) draw(x+i-1, y+j-1);
}

int main() {
    memset(f, '.', sizeof(f));
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, n) rep(j, m) scanf(" %c", f[i+1]+j+1);
    int ans=0;
    rep(i, n) rep(j, m) if(f[i+1][j+1]=='W') ans++, draw(i+1, j+1);
    printf("%d\n", ans);
    return 0;
}


