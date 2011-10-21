#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int ans = 0;
        rep(i, n) {
            vector<pair<int, int> > v;
            v.push_back(mp(0, 0));
            rep(j, m) {
                int a;
                scanf("%d", &a);
                if(a!=-1) v.push_back(mp(a, j));
            }
            sort(v.begin(), v.end());
            rep(j, v.size()-1) {
                const int df = abs(v[j].second-v[j+1].second);
                ans += i*20 + min(df, m-df)*5;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
