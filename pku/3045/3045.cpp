#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n;
long long sum;
pair<int, int> a[50000];

bool can(long long ans) {
    priority_queue<int> q;
    int ix = 0;
    long long cs = sum;
    rep(_, n) {
        while(ix<n && a[ix].first >= cs-ans) q.push(a[ix++].second);
        if(q.empty()) return false;
        cs -= q.top();
        q.pop();
    }
    return true;
}

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d%d", &a[i].second, &a[i].first);
    rep(i, n) a[i].first += a[i].second;
    sum = 0;
    rep(i, n) sum += a[i].second;
    sort(a, a+n, greater<pair<int, int> >());
    long long l=-(1LL<<32), r=(1LL<<32);
    while(r-l>1) {
        long long mid = (l+r)/2;
        if(can(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}
