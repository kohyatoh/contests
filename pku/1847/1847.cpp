#include <stdio.h>
#include <vector>
#include <deque>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, a, b, vis[100];
vector<int> is[100];

int main() {
    scanf("%d%d%d", &n, &a, &b); a--; b--;
    rep(i, n) {
        int k;
        scanf("%d", &k);
        rep(j, k) {
            int t;
            scanf("%d", &t);
            is[i].push_back(t-1);
        }
    }
    deque<pair<int, int> > q;
    q.push_back(mp(a, 0));
    int ans=-1;
    while(!q.empty()) {
        pair<int, int> v=q.front();
        q.pop_front();
        if(v.first==b) { ans=v.second; break; }
        if(vis[v.first]) continue;
        vis[v.first] = 1;
        rep(i, is[v.first].size()) {
            if(i==0) q.push_front(mp(is[v.first][i], v.second));
            else q.push_back(mp(is[v.first][i], v.second+1));
        }
    }
    printf("%d\n", ans);
    return 0;
}

