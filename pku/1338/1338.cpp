#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

vector<long long> ans;
set<long long> s;

int main() {
    priority_queue<long long> q;
    q.push(-1);
    while(!q.empty()) {
        long long v=-q.top(); q.pop();
        if(s.find(v)!=s.end()) continue;
        s.insert(v);
        ans.push_back(v);
        if(ans.size()==1500) break;
        if(s.find(v*2)==s.end()) q.push(-v*2);
        if(s.find(v*3)==s.end()) q.push(-v*3);
        if(s.find(v*5)==s.end()) q.push(-v*5);
    }
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        printf("%lld\n", ans[n-1]);
    }
}

