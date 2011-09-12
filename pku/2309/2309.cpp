#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define ASS(a) (assert(a))
#else
#define LOG(a) ((void)0)
#define ASS(a) ((void)0)
#endif

int main() {
    unsigned T, n;
    scanf("%u", &T);
    while(T--) {
        scanf("%u", &n);
        int ix=0;
        while((n&(1<<ix))==0) ix++;
        printf("%d %d\n", n-(1<<ix)+1, n+((1<<ix)-1));
    }
    return 0;
}


