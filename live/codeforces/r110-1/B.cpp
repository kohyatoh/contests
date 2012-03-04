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
#define INF (1<<28)
#define MOD (YOUR_MODULUS)

#define N (200000)
int n, m, vot[N], s;
int pos[N], neg[N], is[N], ca;

int main() {
    scanf("%d%d", &n, &m);
    rep (i, n) {
        char c;
        int k;
        scanf(" %c%d", &c, &k);
        k--;
        if (c=='+') {
            pos[k]++;
            vot[i] = k+1;
        }
        else {
            neg[k]++;
            vot[i] = -(k+1);
            s++;
        }
    }
    rep (i, n) {
        if (pos[i] + s - neg[i] == m) {
            is[i] = 1;
            ca++;
        }
        LOG(is[i]);
    }
    rep (i, n) {
        const int k = abs(vot[i]) - 1;
        if (vot[i] > 0) {
            if (!is[k]) puts("Lie");
            else {
                if (ca == 1) puts("Truth");
                else puts("Not defined");
            }
        }
        else {
            if (!is[k]) puts("Truth");
            else {
                if (ca == 1) puts("Lie");
                else puts("Not defined");
            }
        }
    }
    return 0;
}
