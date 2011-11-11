#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1LL<<60)
typedef long long Int;

int n, m, u[30000], v[30000], w[30000];
Int di[2000];

inline void add(int x, int y, int c) {
    u[m] = x; v[m] = y; w[m] = c;
    m++;
}

int main() {
    int m1, m2;
    scanf("%d%d%d", &n, &m1, &m2);
    rep(i, n-1) add(i+1, i, 0);
    rep(i, m1) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        add(x-1, y-1, c);
    }
    rep(i, m2) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        add(y-1, x-1, -c);
    }
    rep(i, n) di[i] = INF;
    di[0] = 0;
    rep(k, n) rep(i, m) {
        if(di[v[i]]>di[u[i]]+w[i]) {
            di[v[i]] = di[u[i]]+w[i];
            if(k==n-1) {
                printf("%d\n", -1);
                return 0;
            }
        }
    }
    cout << (di[n-1]<INF ? di[n-1] : -2) << endl;
    return 0;
}
