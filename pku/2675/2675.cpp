#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

pair<double, int> v[65536];
int n, s, id, l;
double f;

int main() {
    while(scanf("%d", &n)!=EOF) {
        rep(i, n) {
            scanf("%d%d%lf", &id, &l, &f);
            v[i].first = l/f;
            v[i].second = id;
        }
        scanf("%d", &s);
        sort(v, v+n);
        printf("%d\n", v[s-1].second);
    }
    return 0;
}
