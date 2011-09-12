#include <stdio.h>
#include <string.h>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BIT {
    static const int N=500000;
    int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void add(int k, int a) { for(; k<N; k|=k+1) x[k]+=a; }
    int sum(int k) { int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
    int rsum(int i, int j) { return i==0 ? sum(j) : sum(j)-sum(i-1); }
} bit;

int n;
pair<int, int> v[500000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) {
            scanf("%d", &v[i].first);
            v[i].second = i;
        }
        stable_sort(v, v+n);
        bit.init();
        long long ans=0;
        rep(i, n) {
            ans += bit.rsum(v[i].second, n-1);
            bit.add(v[i].second, 1);
        }
        cout << ans << endl;
    }
}
