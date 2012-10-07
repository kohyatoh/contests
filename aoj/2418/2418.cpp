#include <stdio.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, T, H, L;
int t[128], h[128];

int solve() {
    int cur = 0;
    for (int i = 0;; i = (i+1)%n) {
        if (t[i] == 0 && h[i] == 0) return i;
        if (t[i] > 0) t[i]--, T++, cur+=10;
        else h[i]--, H++, cur+=100;
        if (T > L) return i;
        if (cur >= 90) {
            int ex = cur - 90;
            while (ex%100 != 0) {
                if (T == 0) return i;
                T--, t[i]++, ex-=10;
            }
            while (ex != 0) {
                if (T >= 10) T-=10, t[i]+=10, ex-=100;
                else if (H > 0) H--, h[i]++, ex-=100;
                else return i;
            }
            cur = 0;
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &T, &H, &L);
    rep (i, n) scanf("%d%d", t+i, h+i);
    printf("%d\n", solve()+1);
    return 0;
}
