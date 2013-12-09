#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int T;
    cin >> T;
    rep (_, T) {
        int n;
        cin >> n;
        map<char, int> sum;
        rep (i, n) {
            string s;
            cin >> s;
            sum[s[0]] += atoi(s.c_str());
        }
        int ans = 0;
        rep (i, 10) {
            ans = max(ans, sum['0' + i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
