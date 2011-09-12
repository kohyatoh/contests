#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, k;

int calc() {
    int ans = 1<<30;
    queue<pair<int, int> > q;
    set<int> vis;
    q.push(mp(0, n));
    while(!q.empty()) {
        pair<int, int> v(q.front());
        q.pop();
        const int cur = v.second;
        if(ans<=v.first) break;
        if(vis.find(cur)!=vis.end()) continue;
        vis.insert(cur);
        ans = min(ans, v.first+abs(cur-k));
        if(cur<k) {
            q.push(mp(v.first+1, cur-1));
            q.push(mp(v.first+1, cur+1));
            q.push(mp(v.first+1, cur*2));
        }
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    printf("%d\n", calc());
    return 0;
}
