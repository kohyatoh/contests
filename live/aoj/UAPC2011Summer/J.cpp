#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define MOD (100000007LL)
typedef long long Int;

struct BIT {
    static const int N=500000;
    Int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void add(int k, Int a) { for(; k<N; k|=k+1) x[k]+=a; }
    Int sum(int k) { Int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
    Int rsum(int i, int j) { return i==0 ? sum(j) : sum(j)-sum(i-1); }
} bit;

int Q, LIM, m;
int query[500000], x[500000];

void mami(int id) {
    bit.add(id, -1);
    m--;
}

int get(int nth) {
    int l=-1, r=BIT::N-1;
    while(r-l>1) {
        const int mid = (l+r)/2;
        if(bit.sum(mid)<=nth) l = mid;
        else r = mid;
    }
    return r;
}

int main() {
    for(;;) {
        scanf("%d%d", &Q, &LIM);
        if(Q==0 && LIM==0) return 0;
        rep(i, Q) scanf("%d%d", query+i, x+i);
        bit.init();
        m = 0;
        map<int, int> ix;
        rep(i, Q) {
            if(query[i]==0) {
                bit.add(i, 1);
                ix[x[i]] = i;
                m++;
                if(m>LIM) mami(get(0));
            }
            else if(query[i]==1) {
                mami(get(x[i]-1));
            }
            else if(query[i]==2) {
                printf("%d\n", x[get(x[i]-1)]);
            }
            else {
                mami(ix[x[i]]);
            }
        }
        puts("end");
    }
}


