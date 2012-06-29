#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    map<int, int> pt, rank;
    vector<int> ps;
    for (;;) {
        int x, y;
        scanf("%d,%d", &x, &y);
        if (x == 0 && y == 0) break;
        pt[x] = y;
        ps.push_back(y);
    }
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    rep (i, ps.size()) rank[ps[i]] = ps.size()-i;
    int k;
    while (scanf("%d", &k) != EOF) printf("%d\n", rank[pt[k]]);
    return 0;
}
