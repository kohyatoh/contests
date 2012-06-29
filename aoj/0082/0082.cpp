#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

const int dat[8] = {4, 1, 4, 1, 2, 1, 2, 1};
int a[8];

int main() {
    while (scanf("%d", a) != EOF) {
        rep (i, 7) scanf("%d", a+i+1);
        vector<int> c, ans;
        rep (i, 8) c.push_back(dat[i]);
        int ansk = 1<<30;
        rep (_, 8) {
            rotate(c.begin(), c.begin()+1, c.end());
            int k = 0;
            rep (i, 8) k += max(0, a[i]-c[i]);
            if (ansk > k) ansk = k, ans = c;
            else if (ansk == k) ans = min(ans, c);
        }
        rep (i, 8) printf("%d%c", ans[i], "\n "[i<7]);
    }
    return 0;
}

