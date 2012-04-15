#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

vector<vector<pair<int, int> > > ans;

void rec(int n, int x) {
    if (n == 1) return;
    vector<pair<int, int> > a;
    for (int i = 1; i < n; i+=2) {
        a.push_back(mp(x*(i-1)+x-1, x*i+x-1));
    }
    if (a.size()) ans.push_back(a);
    rec(n/2, x*2);
    vector<pair<int, int> > b;
    for (int i = 2; i < n; i+=2) {
        b.push_back(mp(x*(i-1)+x-1, x*i+x-1));
    }
    if (b.size()) ans.push_back(b);
}

int main() {
    int n;
    scanf("%d", &n);
    rec(n, 1);
    printf("%d\n", (int)ans.size());
    rep (k, ans.size()) {
        printf("%d", ans[k].size());
        rep (i, ans[k].size()) {
            const int a = ans[k][i].first + 1;
            const int b = ans[k][i].second + 1;
            printf(" %d+%d=%d", a, b, b);
        }
        printf("\n");
    }
    return 0;
}
