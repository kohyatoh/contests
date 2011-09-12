#include <stdio.h>
#include <map>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int P, M;
map<pair<int, int>, int> dp[300];
void update(int i, int m, int b, int a) {
    if(dp[i].find(mp(m, b))==dp[i].end()) dp[i][mp(m, b)]=a;
    else dp[i][mp(m, b)]=min(dp[i][mp(m, b)], a);
}

int main() {
    scanf("%d%d", &M, &P);
    int mk=0, nk=0;;
    rep(i, P) {
        int a, b;
        scanf("%d%d", &b, &a);
        nk=mk=mk+2;
        update(i, nk, b, a);
        if(i>0) for(map<pair<int, int>, int>::iterator it=dp[i-1].begin();
                it!=dp[i-1].end(); it++) {
            if(it->first.first>=nk) break;
            if(it->first.second+b<=M && it->second+a<=M) {
                mk = min(mk, it->first.first);
                update(i, it->first.first, it->first.second+b, it->second+a);
            }
            if(it->first.first+1<nk && it->second+b<=M) {
                mk = min(mk, it->first.first+1);
                update(i, it->first.first+1, it->second+b, a);
            }
        }
    }
    printf("%d\n", mk+1);
    return 0;
}
