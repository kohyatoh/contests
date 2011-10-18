#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
pair<int, int> a[100000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d%d", &a[i].first, &a[i].second);
        sort(a, a+n);
        int ans = 1, my=a[n-1].second;
        for(int i=n-2; i>=0; i--) if(a[i].second>my) {
            ans++;
            my = a[i].second;
        }
        printf("%d\n", ans);
    }
}
