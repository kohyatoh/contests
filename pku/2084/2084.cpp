#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

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
    BigNum& operator*=(const BigNum& x) {
        Int t[MAXDIGIT];
        memset(t, 0, sizeof(t));
        for(int i=0; i<n; i++) for(int j=0; j<x.n; j++) {
            t[i+j] += dig[i]*x.dig[j];
        }
        n += x.n;
        memcpy(dig, t, sizeof(t));
        return normalize();
    }
};

BigNum operator+(BigNum a, const BigNum& b) { return a+=b; }
BigNum operator*(BigNum a, const BigNum& b) { return a*=b; }
ostream& operator<<(ostream &os, const BigNum& x) {
    os << x.dig[x.n-1];
    for(int i=x.n-2; i>=0; i--) os<<setw(x.BW)<<setfill('0')<<x.dig[i];
    return os;
}

int n;
BigNum dp[200];

int main() {
    dp[0] = 1;
    rep(i, 100) rep(j, i+1) dp[i+1]+=dp[j]*dp[i-j];
    for(;;) {
        cin >> n;
        if(n==-1) return 0;
        cout << dp[n] << endl;
    }
}

