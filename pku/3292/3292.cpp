#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int pt[2000000], sp[2000000], s[2000000];

int main() {
    vector<int> v;
    for(int i=5; i<1000002; i+=4) if(pt[i]==0) {
        v.push_back(i);
        for(int j=i*5; j<1000002; j+=i*4) pt[j] = i;
    }
    rep(i, v.size()) rep(j, i+1) {
        const int k = v[i]*v[j];
        if(k>=1000002) break;
        sp[k] = 1;
    }
    s[0] = 0;
    rep(i, 1000002) s[i+1] = s[i]+sp[i];
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        printf("%d %d\n", n, s[n+1]);
    }
}
