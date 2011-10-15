#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, m, a[2000], t[2000];

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, n) scanf("%d", a+i);
        rep(i, n) t[i] = m/a[i]*a[i];
        pair<int, int> ans(m+1, 0);
        rep(i, n) ans = min(ans, mp(t[i], a[i]));
        vector<int> cs;
        rep(i, n) if(ans==mp(t[i], a[i])) cs.push_back(i+1);
        printf("%d\n", cs.size()==1 ? cs[0] : n);
    }
}
