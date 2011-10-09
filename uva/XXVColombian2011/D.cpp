#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int N, M, K, A[20];

int solve() {
    set<int> s;
    rep(x, M+1) {
        Int v = 0;
        rep(i, K+1) v = (v*x+A[K-i])%(N+1);
        s.insert(v);
    }
    return s.size();
}

int main() {
    for(;;) {
        scanf("%d%d", &N, &M);
        if(N==0 && M==0) return 0;
        scanf("%d", &K);
        rep(i, K+1) scanf("%d", A+i);
        printf("%d\n", solve());
    }
}

