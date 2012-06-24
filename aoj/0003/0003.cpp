#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a[3];
        rep (i, 3) scanf("%d", a+i);
        sort(a, a+3);
        bool ans = ((Int)a[0]*a[0]+(Int)a[1]*a[1] == (Int)a[2]*a[2]);
        puts(ans ? "YES" : "NO");
    }
    return 0;
}
