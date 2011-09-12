#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

const int dx[6] = { 1, 1, 0, -1, -1, 0 };
const int dy[6] = { 1, 0, -1, -1, 0, 1 };
Int dp[32][128][128];

int main() {
    dp[0][64][64] = 1;
    rep(i, 20) {
        for(int x=2; x<126; x++) for(int y=2; y<126; y++) rep(d, 6) {
            dp[i+1][x+dx[d]][y+dy[d]] += dp[i][x][y];
        }
    }
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        cout << dp[n][64][64] << endl;
    }
    return 0;
}
