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
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

int n, w[16], g, r[16];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d", w+i);
        scanf("%d", &g);
        const int s = (*max_element(w, w+n)+49)/50;
        rep(i, n) r[i] = s*50-w[i];
        for(int x=0; ; x++) {
            while(g>0) {
                sort(r, r+n);
                if(r[n-3]==0) break;
                rep(i, 3) r[n-3+i]--;
                g--;
            }
            if(g<=0) {
                printf("%d\n", s+x);
                break;
            }
            rep(i, n) r[i] += 50;
        }
    }
}


