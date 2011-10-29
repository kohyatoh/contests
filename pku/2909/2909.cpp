#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int pt[60000];

int main() {
    vector<int> ps;
    pt[0] = pt[1] = 1;
    for(int i=2; i<60000; i++) if(pt[i]==0) {
        ps.push_back(i);
        for(int j=i+i; j<60000; j+=i) pt[j] = i;
    }
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        int ans = 0;
        rep(i, ps.size()) {
            if(n-ps[i]<ps[i]) break;
            ans += pt[n-ps[i]]==0;
        }
        printf("%d\n", ans);
    }
}
