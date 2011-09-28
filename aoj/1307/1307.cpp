#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, m, D[500], cnt[500], xs[40], as[40];
set<vector<int> > ans;

void rec(int c, int k) {
    if(c==N) {
        rep(i, N) as[i] = xs[i];
        sort(as, as+N);
        rep(i, N-1) as[i] = as[i+1]-as[i];
        ans.insert(vector<int>(as, as+N-1));
        return ;
    }
    while(cnt[D[k]]==0) k++;
    rep(t, 2) {
        int x = t ? D[k] : D[0]-D[k];
        xs[c] = x;
        bool ok = true;
        rep(i, c) if(cnt[abs(xs[i]-x)]--==0) ok = false;
        if(ok) rec(c+1, k+1);
        rep(i, c) cnt[abs(xs[i]-x)]++;
    }
}

int main() {
    for(;;) {
        scanf("%d", &N);
        if(N==0) return 0;
        m = N*(N-1)/2;
        rep(i, m) scanf("%d", D+i);
        memset(cnt, 0, sizeof(cnt));
        rep(i, m) cnt[D[i]]++;
        xs[0] = 0;
        xs[1] = D[0];
        cnt[D[0]]--;
        ans.clear();
        rec(2, 1);
        for(set<vector<int> >::iterator it=ans.begin(); it!=ans.end(); it++) {
            const int n = it->size();
            rep(i, n) printf("%d%c", (*it)[i], i<n-1 ? ' ' : '\n');
        }
        puts("-----");
    }
}
