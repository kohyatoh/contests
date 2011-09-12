#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

bool np[50000];

int main() {
    for(int i=3; i*i<50000; i+=2) if(!np[i]) {
        for(int j=i*i; j<50000; j+=i) np[j]=true;
    }
    vector<int> pr;
    pr.push_back(2);
    for(int i=3; i<50000; i+=2) if(!np[i]) pr.push_back(i);
    for(;;) {
        int m, a, b;
        scanf("%d%d%d", &m, &a, &b);
        if(m==0) return 0;
        int maxm=-1, maxp, maxq;
        for(int i=0; pr[i]*pr[i]<=m; i++) {
            int p=pr[i];
            int u=min(m/p, p*b/a);
            int q=*(upper_bound(pr.begin()+i, pr.end(), u)-1);
            if(maxm<p*q) maxm=p*q, maxp=p, maxq=q;
        }
        printf("%d %d\n", maxp, maxq);
    }
}

