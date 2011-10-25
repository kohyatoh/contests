#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define M (151200)

int main() {
    vector<int> as, bs;
    for(int i=0; i*i*i<=M; i++) as.push_back(i*i*i);
    for(int i=0; i*(i+1)*(i+2)/6<=M; i++) bs.push_back(i*(i+1)*(i+2)/6);
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        int ans = 0, j = bs.size()-1;
        rep(i, as.size()) {
            while(j>=0 && as[i]+bs[j]>n) j--;
            if(j>=0) ans = max(ans, as[i]+bs[j]);
        }
        printf("%d\n", ans);
    }
}
