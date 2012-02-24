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
inline void cmax(int &a, int b) { if (a < b) a = b; }

int pt[200000];
bool on[200000];
set<int> hs[200000];
int n, m;

int main() {
    for (int i = 2; i < 200000; i++) if (pt[i] == 0) {
        for (int j = i+i; j < 200000; j+=i) pt[j] = i;
    }
    scanf("%d%d", &n, &m);
    rep (_, m) {
        char c;
        int k;
        scanf(" %c%d", &c, &k);
        if (c == '+') {
            if (on[k]) puts("Already on");
            else {
                int col = -1;
                for (int i = k; i > 1; ) {
                    const int p = pt[i] ? pt[i] : i;
                    if (!hs[p].empty()) {
                        col = *hs[p].begin();
                        break;
                    }
                    while (i%p==0) i /= p;
                }
                if (col != -1) printf("Conflict with %d\n", col);
                else {
                    puts("Success");
                    on[k] = true;
                    for (int i = k; i > 1; ) {
                        const int p = pt[i] ? pt[i] : i;
                        hs[p].insert(k);
                        while (i%p==0) i /= p;
                    }
                }
            }
        }
        else if (c == '-') {
            if (!on[k]) puts("Already off");
            else {
                puts("Success");
                on[k] = false;
                for (int i = k; i > 1; ) {
                    const int p = pt[i] ? pt[i] : i;
                    hs[p].erase(k);
                    while (i%p==0) i /= p;
                }
            }
        }
    }
    return 0;
}
