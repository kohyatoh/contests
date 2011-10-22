#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int N, K, a[100000], b[100000];
pair<int, int> v[100000];

int main() {
    scanf("%d%d", &N, &K);
    rep(i, N) scanf("%d%d", a+i, b+i);
    rep(i, N) v[i] = mp(a[i], i);
    sort(v, v+N);
    reverse(v, v+N);
    int ans = -1, ansi = -1;
    rep(i, K) if(ans<b[v[i].second]) {
        ans = b[v[i].second];
        ansi = v[i].second;
    }
    printf("%d\n", ansi+1);
    return 0;
}
