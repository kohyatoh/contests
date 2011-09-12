#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int T, n, x[10000], y[10000];
pair<int, int> s[10000];

bool can() {
    long long sx=0, sy=0;
    rep(i, n) sx+=x[i], sy+=y[i];
    if(sx%n || sy%n) return false;
    int cx=sx/n, cy=sy/n;
    sort(s, s+n);
    rep(i, n) if(!binary_search(s, s+n, mp(2*cx-x[i], 2*cy-y[i]))) return false;
    return true;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        rep(i, n) {
            scanf("%d%d", x+i, y+i);
            x[i]*=2, y[i]*=2;
            s[i].first=x[i], s[i].second=y[i];
        }
        puts(can() ? "yes" : "no");
    }
    return 0;
}

