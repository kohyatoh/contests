#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;

int solve(int n) {
    int c = 0;
    set<int> vis;
    while (n >= 10 && vis.count(n) == 0) {
        vis.insert(n);
        int nx = 0, d = 10;
        while (d <= n) {
            nx = max(nx, (n%d)*(n/d));
            d *= 10;
        }
        n = nx;
        c++;
    }
    if (n < 10) return c;
    return -1;
}

int main() {
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}
