#include <stdio.h>
#include <numeric>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct coin { int a, c, d; };
bool operator<(const coin& l, const coin& r) {
    return l.d!=r.d?l.d<r.d:l.a<r.a;
}

int n, m;
coin coins[200];
#ifdef __WIN32
int dp[100010], dc[100010];
volatile int ans;
#else
int _dp[100010], _dc[100010];
volatile int _ans;
#endif

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, n) scanf("%d", &coins[i].a);
        rep(i, n) scanf("%d", &coins[i].c);
        rep(i, n) coins[i].d=coins[i].a*coins[i].c;
        sort(coins, coins+n);
#ifdef __WIN32
        rep(i, m+1) dp[i]=0;
        dp[0]=1;
        ans=0;
#else
        rep(i, m+1) _dp[i]=0;
        _dp[0]=1;
        _ans=0;
#endif
        int a, c, lim, col;
        int mm=0;
        rep(i, n) {
            a=coins[i].a, c=coins[i].c, col=i+2;
            mm += a*c;
            lim=min(m-a, mm)+1;
__asm__ __volatile__(
        "xorl    %%eax, %%eax;"
        "movl    %3, %%ecx;"
        "jmp     .Lloop_test;"
    ".Lloop_inc:;"
        "addl    $1, %%eax;"
        "addl    $1, %%ecx;"
    ".Lloop_test:;"
        "cmpl    %%eax, %2;"
        "jle     .Lloop_end;"
        "cmpl    $0, _dp(,%%eax,4);"
        "je      .Lloop_inc;"
        "cmpl    $0, _dp(,%%ecx,4);"
        "jne     .Lloop_inc;"
    ".Lloop:;"
        "cmpl    _dp(,%%eax,4), %1;"
        "je      .Lloop_i2;"
    ".Lloop_i1:;"
        "addl    $1, _ans;"
        "movl    %1, _dp(,%%ecx,4);"
        "movl    $1, _dc(,%%ecx,4);"
        "jmp     .Lloop_inc;"
    ".Lloop_i2:;"
        "cmpl    _dc(,%%eax,4), %0;"
        "je      .Lloop_inc;"
        "addl    $1, _ans;"
        "movl    %1, _dp(,%%ecx,4);"
        "movl    $1, %%ebx;"
        "addl    _dc(,%%eax,4), %%ebx;"
        "movl    %%ebx, _dc(,%%ecx,4);"
        "jmp     .Lloop_inc;"
    ".Lloop_end:;"
: : "r"(c), "r"(col), "r"(lim), "m"(a): "%eax", "%ebx", "%ecx");
        }
#ifdef __WIN32
       printf("%d\n", ans);
#else
       printf("%d\n", _ans);
#endif
    }
}
