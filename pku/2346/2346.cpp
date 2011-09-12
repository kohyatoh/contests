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

int f(int a) {
    int s=0;
    while(a>0) { s+=a%10; a/=10; }
    return s;
}

int c[100];

int main() {
    int n;
    scanf("%d", &n);
    int a=1;
    rep(i, n/2) a*=10;
    LOG(a);
    rep(i, a) c[f(i)]++;
    int ans=0;
    rep(i, a) ans += c[f(i)];
    printf("%d\n", ans);
    return 0;
}


