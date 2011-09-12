#include <stdio.h>
#include <stack>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, h[100000];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", h+i);
    h[n++]=2000000000;
    stack<pair<int, int> > s;
    unsigned ans=0;
    rep(i, n) {
        while(!s.empty() && s.top().first<=h[i]) {
            ans += i-s.top().second-1;
            s.pop();
        }
        s.push(mp(h[i], i));
    }
    printf("%u\n", ans);
    return 0;
}

