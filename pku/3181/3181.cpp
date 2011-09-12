#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
typedef long long Int;

struct BigNum {
    static const Int B = 10000;      // base (power of 10)
    static const int BW = 4;         // log(10) B
    static const int MAXDIGIT = 100; // repr BW*MAXDIGIT digs (in base 10)
    Int dig[MAXDIGIT];
    int n;
    BigNum(Int a=0, int n=1) : n(n) {
        memset(dig, 0, sizeof(dig));
        dig[0] = a;
    }
    BigNum& normalize() {
        Int c=0;
        for(int i=0; i<n; i++) {
            while(dig[i]<0) dig[i+1]-=1, dig[i]+=B;
            Int a = dig[i]+c;
            dig[i] = a%B;
            c = a/B;
        }
        while(c>0) dig[n++]=c%B, c/=B;
        while(n>1 && dig[n-1]==0) n--;
        return *this;
    }
    BigNum& operator+=(const BigNum& x) {
        if(n<x.n) n=x.n;
        for(int i=0; i<x.n; i++) dig[i]+=x.dig[i];
        return normalize();
    }
} dp[2000];

int main() {
    int N, K;
    cin >> N >> K;
    dp[0] += 1;
    for(int k=1; k<=K; k++) {
        for(int i=0; i<=N-k; i++) dp[i+k] += dp[i];
    }
    const int m = dp[N].n;
    printf("%d", dp[N].dig[m-1]);
    for(int i=m-2; i>=0; i--) printf("%04d", dp[N].dig[i]);
    printf("\n");
    return 0;
}
