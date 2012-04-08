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
#define MOD (YOUR_MODULUS)

#define N (2000000)
int n, m, a[N], b[N];
int of[N];

int main() {
    memset(of, -1, sizeof(of));
    scanf("%d%d", &n, &m);
    rep (i, n) scanf("%d", a+i);
    rep (i, m) scanf("%d", b+i);
    rep (i, m) of[b[i]] = i;
    deque<int> q;
    int ans = 0;
    rep (i, n*2) {
        const int ix = of[a[i%n]];
        if (ix == -1) q.clear();
        else {
            bool pushed = false;
            while (!pushed) {
                if (q.size() <= 1) {
                    q.push_back(ix);
                    pushed = true;
                }
                else {
                    const int s = q[0];
                    const int e = q[q.size()-1];
                    if (s < e) {
                        if (e < ix || ix < s) {
                            q.push_back(ix);
                            pushed = true;
                        }
                    }
                    else if (e < s) {
                        if (e < ix && ix < s) {
                            q.push_back(ix);
                            pushed = true;
                        }
                    }
                }
                if (!pushed) {
                    q.pop_front();
                }
            }
        }
        ans = max(ans, (int)q.size());
    }
    printf("%d\n", ans);
    return 0;
}

