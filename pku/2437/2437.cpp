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
#define INF MY_INFINITY

int n, L;
pair<int, int> v[10000];

int main() {
    scanf("%d%d", &n, &L);
    rep(i, n) scanf("%d%d", &v[i].first, &v[i].second);
    sort(v, v+n);
    int c=0, at=-1;
    rep(i, n) {
        if(at<=v[i].first) {
            at = v[i].first + L;
            c++;
        }
        if(at<v[i].second) {
            int k = (v[i].second-at+L-1)/L;
            at += L*k;
            c += k;
        }
    }
    printf("%d\n", c);
    return 0;
}


