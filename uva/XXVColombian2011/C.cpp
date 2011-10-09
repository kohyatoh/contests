#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)

int M, N, en[100], dp[100000];
vector<int> b[100];

int solve(vector<int> doc) {
    memset(en, 0, sizeof(en));
    rep(i, M) rep(j, doc.size()) {
        if(binary_search(b[i].begin(), b[i].end(), doc[j])) en[i] |= 1<<j;
    }
    rep(i, M) rep(j, b[i].size()) {
        if(!binary_search(doc.begin(), doc.end(), b[i][j])) en[i] = 0;
    }
    const int kk = 1<<doc.size();
    rep(i, kk) dp[i] = INF;
    dp[0] = 0;
    rep(b, kk) rep(i, M) dp[b|en[i]] = min(dp[b|en[i]], dp[b]+1);
    return dp[kk-1]<INF ? dp[kk-1] : 0;
}

vector<int> readDoc() {
    vector<int> a;
    int k, t;
    scanf("%d", &k);
    rep(_, k) {
        scanf("%d", &t);
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    return a;
}

int main() {
    for(;;) {
        scanf("%d%d", &M, &N);
        if(M==0 && N==0) return 0;
        rep(i, 100) b[i].clear();
        vector<int> ans;
        rep(i, M) b[i] = readDoc();
        rep(i, N) ans.push_back(solve(readDoc()));
        rep(i, ans.size()) {
            printf("%d%c", ans[i], i<(int)ans.size()-1 ? ' ' : '\n');
        }
    }
}
