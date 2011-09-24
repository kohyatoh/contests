#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
typedef long long Int;

int r, c, q, A[60000], B[60000], ord[60000];
int re[60000], ce[60000];

int main() {
    for(;;) {
        scanf("%d%d%d", &r, &c, &q);
        if(r==0 && c==0 && q==0) return 0;
        rep(i, q) scanf("%d%d%d", A+i, B+i, ord+i);
        memset(re, 0, sizeof(re));
        memset(ce, 0, sizeof(ce));
        int rc=r, cc=c;
        unsigned ans = 0;
        for(int i=q-1; i>=0; i--) {
            if(A[i]==0 && re[B[i]]==0) {
                if(ord[i]==1) ans += cc;
                rc--;
                re[B[i]] = 1;
            }
            if(A[i]==1 && ce[B[i]]==0) {
                if(ord[i]==1) ans += rc;
                cc--;
                ce[B[i]] = 1;
            }
        }
        printf("%u\n", ans);
    }
}

