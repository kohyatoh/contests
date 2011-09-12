#include <stdio.h>
#include <iostream>
#include <math.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;

bool is_prime(unsigned n) {
    if(n<2) return false;
    unsigned u = sqrt(n)+2;
    for(unsigned i=2; i<u && i<n; i++) if(n%i==0) return false;
    return true;
}

bool e_prime[1000001];

void make_e_prime(unsigned L, unsigned U) {
    unsigned upper = sqrt(U)+2;
    rep(i, U-L+1) e_prime[i] = true;
    if(L<=1) e_prime[1-L] = false;
    for(unsigned i=2; i<upper; i++) if(is_prime(i)) {
        unsigned b = (L<i) ? i+i : ((L%i==0) ? L : (L/i+1)*i);
        if(b==i) b += i;
        while(b<=U) { e_prime[b-L]=false; b+=i; }
    }
}

int main() {
    unsigned L, U;
    while(scanf("%d%d", &L, &U)!=EOF) {
        make_e_prime(L, U);
        int mind=-1, maxd=0;
        unsigned min1, min2, max1, max2;
        int pre=-1;
        rep(i, U-L+1) if(e_prime[i]) {
            if(pre!=-1) {
                int cur = unsigned(i)+L;
                if(mind==-1 || mind>cur-pre) {
                    mind = cur-pre; min1=pre; min2=cur;
                }
                if(maxd<cur-pre) {
                    maxd = cur-pre; max1=pre; max2=cur;
                }
            }
            pre = unsigned(i)+L;
        }
        if(mind==-1) printf("There are no adjacent primes.\n");
        else printf("%u,%u are closest, %d,%u are most distant.\n", min1, min2, max1, max2);
    }
    return 0;
}
