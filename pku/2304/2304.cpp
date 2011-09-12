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

int diff(int a, int b) {
    return (b-a+40)%40;
}

int main() {
    int a, b, c, d;
    for(;;) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(a==0 && b==0 && c==0 && d==0) return 0;
        printf("%d\n", 360/40*(diff(b, a)+diff(b, c)+diff(d, c)+40*3));
    }
}


