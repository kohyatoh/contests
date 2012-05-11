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

int n, a[500000], b[500000], of[500000];

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", a+i);
    rep (i, n) scanf("%d", b+i);
    rep (i, n) of[b[i]] = i;
    rep (i, n) a[i] = of[a[i]];
    int e = 1;
    while (e < n && a[e-1] < a[e]) e++;
    printf("%d\n", n-e);
    return 0;
}
