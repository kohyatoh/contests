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

int b;
char ps[1111], ms[20], rs[20];

int main() {
    for(;;) {
        scanf("%d", &b);
        if(b==0) return 0;
        scanf(" %s %s", ps, ms);
        long long m=0;
        for(char *p=ms; *p; p++) m=m*b+*p-'0';
        long long k=0;
        for(char *p=ps; *p; p++) k=(k*b+*p-'0')%m;
        int n=0;
        do { rs[n++]=k%b; k/=b; } while(k>0);
        rep(i, n) putchar('0'+rs[n-1-i]);
        putchar('\n');
    }
}


