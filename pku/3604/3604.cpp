#include <stdio.h>
#define M (5000001)
inline int sq(int a) { return a*a; }

int pt[M], memo[M];

int f(int n) {
    if(memo[n]!=0) return memo[n];
    const int q = pt[n];
    int p = n, c = 1;
    while(p%q==0) p/=q, c++;
    return memo[n] = f(p)*sq(c*(c+1)/2);
}

int main() {
    for(int i=2; i<M; i+=2) pt[i] = 2;
    for(int i=3; i<M; i+=2) if(pt[i]==0) {
        pt[i] = i;
        if(i<2300) for(int j=i*i; j<M; j+=i) pt[j] = i;
    }
    memo[1] = 1;
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", f(n));
    }
    return 0;
}
