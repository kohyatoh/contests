#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        double ans = 0;
        for(long long i=0, b=1; b<=n; i++, b*=2) {
            const long long r = max(0LL, n%(b*2)-b);
            const double p = (double)(n/(b*2)*b+r)/n;
            ans += b * p * (1-p) * 2;
        }
        printf("%.6f\n", ans);
    }
    return 0;
}
