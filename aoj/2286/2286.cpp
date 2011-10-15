#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;
#define M (1000001)

int pt[M];
void build_pt() {
    for(int i=2; i<M; i++) if(pt[i]==0) {
        for(int j=i+i; j<M; j+=i) pt[j] = i;
    }
}

// Euler's totient function (k>=2)
Int tot(int k) {
    Int r = k;
    while(k>1) {
        const int b = pt[k] ? pt[k] : k;
        r -= r/b;
        while(k%b==0) k/=b;
    }
    return r;
}

Int sum[M];

int main() {
    build_pt();
    sum[1] = 2;
    for(int i=2; i<M; i++) sum[i] = sum[i-1]+tot(i);
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        cout << sum[n] << endl;
    }
    return 0;
}
