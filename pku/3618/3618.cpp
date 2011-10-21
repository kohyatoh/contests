#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int T, N;
pair<int, int> xs[100000];

int main() {
    scanf("%d%d", &T, &N);
    rep(i, N) {
        int x;
        scanf("%d", &x);
        xs[i] = mp(abs(x), x);
    }
    sort(xs, xs+N);
    int ans = 0, t = 0, x = 0;
    rep(i, N) {
        t += abs(x-xs[i].second);
        x = xs[i].second;
        if(t>T) break;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
