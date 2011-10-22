#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

struct MBIT {
    static const int N = 1000000;
    int x[N];
    void update(int k, int a) {
        for(; k<N && x[k]>a; k|=k+1) x[k] = a;
    }
    int min(int k) {
        int s = 0;
        for(; k>=0; k=(k&(k+1))-1) s = std::min(s, x[k]);
        return s;
    }
} bit;

pair<pair<int, int>, int> xs[2000];

int main() {
    int N, M, R;
    scanf("%d%d%d", &N, &M, &R);
    rep(i, M) {
        int s, t, f;
        scanf("%d%d%d", &s, &t, &f);
        xs[i] = mp(mp(s, t+R), f);
    }
    sort(xs, xs+M);
    int ans = 0;
    rep(i, M) {
        const int s = xs[i].first.first;
        const int t = xs[i].first.second;
        const int v = -bit.min(s)+xs[i].second;
        ans = max(ans, v);
        if(t<N) bit.update(t, -v);
    }
    printf("%d\n", ans);
    return 0;
}

