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
#define INF (1<<28)
#define MOD (YOUR_MODULUS)


class DropCoins {
    public:
    int getMinimum(vector <string> b, int K) {
        const int n = b.size();
        const int m = b[0].size();
        int ans = INF;
        for(int l=0; l<=n; l++) for(int r=l; r<=n; r++) {
            for(int p=0; p<=m; p++) {
                int s = 0;
                for(int q=p+1; q<=m; q++) {
                    for(int i=l; i<r; i++) if(b[i][q-1]=='o') s++;
                    if(s==K) {
                        ans = min(ans, l+(n-r)+min(l, n-r)+p+(m-q)+min(p, m-q));
                    }
                }
            }
        }
        return ans<INF ? ans : -1;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
