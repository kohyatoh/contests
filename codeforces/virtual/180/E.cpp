#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int N, M, K;
vector<int> x[300000];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    rep (i, N) {
        int c;
        scanf("%d", &c);
        c--;
        x[c].push_back(i);
    }
    int ans = 0;
    rep (k, M) {
        int j = 0;
        rep (i, x[k].size()) {
            while (j < (int)x[k].size() && (x[k][j]-x[k][i]+1)-(j-i+1) <= K) {
                if (j-i+1 > ans) ans = j-i+1;
                j++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
