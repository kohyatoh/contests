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
#else
#define LOG(a) ((void)0)
#define ASS(a) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, -1, 0, 1};
const char of[] = "RSP";

int T, h, w, n, f[100][100], g[100][100];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &h, &w, &n);
        rep(i, h) rep(j, w) {
            char ch;
            scanf(" %c", &ch);
            f[i][j] = find(of, of+3, ch)-of;
            LOG(f[i][j]);
        }
        rep(k, n) {
            rep(i, h) rep(j, w) {
                g[i][j] = f[i][j];
                rep(d, 4) {
                    const int ni=i+di[d], nj=j+dj[d];
                    if(0<=ni && ni<h && 0<=nj && nj<w) {
                        if(f[i][j]==(f[ni][nj]+1)%3) g[i][j]=f[ni][nj];
                    }
                }
            }
            rep(i, h) rep(j, w) f[i][j]=g[i][j];
        }
        rep(i, h) {
            rep(j, w) putchar(of[f[i][j]]);
            putchar('\n');
        }
        if(T) putchar('\n');
    }
    return 0;
}


