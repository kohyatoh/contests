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
        rep(i, pr.size()) {
            for(int j=i; j<(int)pr.size(); j++) {
                if(a*pr[j]>b*pr[i]) break;
                long long cm=pr[i]*pr[j];
                if(cm>m) break;
                if(maxm<cm) {
                    maxm=cm;
                    maxp=pr[i];
                    maxq=pr[j];
                }
            }
        }
        printf("%d %d\n", maxp, maxq);
    }
}

