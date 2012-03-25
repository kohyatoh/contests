#include <iostream>
using namespace std;
typedef long long Int;


Int solve(Int x, Int l1, Int r1, Int l2, Int r2) {
    if (x == 0) return 1;
    if (l1 > x) l1 -= x+1, r1 -= x+1;
    if (l2 > x) l2 -= x+1, r2 -= x+1;
    Int ans = max(0LL, min(r1, r2) - max(l1, l2) + 1);
    if (l1 <= x && x <= r1 && l2 <= x && x <= r2) {
        if (l1 == 0 || r1 == x*2) ans = max(ans, max(x-l2, r2-x));
        else if (l2 == 0 || r2 == x*2) ans = max(ans, max(x-l1, r1-x));
        else {
            if (l1 <= x-1 && r2 >= x+1) {
                ans = max(ans, solve(x/2, l1, x-1, 0, r2-x-1));
            }
            if (l2 <= x-1 && r1 >= x+1) {
                ans = max(ans, solve(x/2, l2, x-1, 0, r1-x-1));
            }
        }
    }
    else if (l1 <= x && x <= r1) {
        if (l1 == 0 || r1 == x*2) ans = max(ans, r2-l2+1);
        else {
            if (l1 <= x-1) ans = max(ans, solve(x/2, l1, x-1, l2, r2));
            if (r1 >= x+1) ans = max(ans, solve(x/2, 0, r1-x-1, l2, r2));
        }
    }
    else if (l2 <= x && x <= r2) {
        if (l2 == 0 || r2 == x*2) ans = max(ans, r1-l1+1);
        else {
            if (l2 <= x-1) ans = max(ans, solve(x/2, l2, x-1, l1, r1));
            if (r2 >= x+1) ans = max(ans, solve(x/2, 0, r2-x-1, l1, r1));
        }
    }
    else {
        ans = max(ans, solve(x/2, l1, r1, l2, r2));
    }
    return ans;
}

int main() {
    Int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    cout << solve((1LL<<36)-1, l1-1, r1-1, l2-1, r2-1) << endl;
    return 0;
}
