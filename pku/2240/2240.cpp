#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m;
double dp[50][50];

int main() {
    for(int q=0;; q++) {
        cin >> n;
        if(n==0) return 0;
        map<string, int> dict;
        rep(i, n) {
            string name;
            cin >> name;
            dict[name]=i;
        }
        rep(i, 50) rep(j, 50) dp[i][j]=i==j;
        cin >> m;
        rep(i, m) {
            string c1, c2;
            double r;
            cin >> c1 >> r >> c2;
            dp[dict[c1]][dict[c2]] = r;
        }
        rep(k, n) rep(i, n) rep(j, n) dp[i][j]=max(dp[i][j], dp[i][k]*dp[k][j]);
        bool f=false;
        rep(i, n) if(dp[i][i]>1) f=true;
        printf("Case %d: %s\n", q+1, f?"Yes":"No");
    }
}

