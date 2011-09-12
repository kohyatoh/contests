#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int dp[110][110], pr[110][110];
vector<string> strs[2];

int main() {
    for(;;) {
        string s;
        rep(i, 2) {
            strs[i].clear();
            for(;;) {
                if(!(cin>>s)) return 0;
                if(s=="#") break;
                strs[i].push_back(s);
            }
        }
        rep(i, 110) rep(j, 110) dp[i][j]=0;
        rep(i, strs[0].size()) rep(j, strs[1].size()) {
            if(strs[0][i]==strs[1][j]) {
                dp[i+1][j+1] = dp[i][j]+1;
                pr[i+1][j+1] = -1;
            }
            else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                pr[i+1][j+1] = dp[i+1][j]>dp[i][j+1];
            }
        }
        vector<string> r;
        int x=strs[0].size(), y=strs[1].size();
        while(x>0 && y>0) {
            if(pr[x][y]==-1) r.push_back(strs[0][x-1]), x--, y--;
            else if(pr[x][y]==0) x--;
            else if(pr[x][y]==1) y--;
        }
        for(int i=r.size()-1; i>=0; i--) {
            cout << r[i];
            if(i==0) cout << endl; else cout << ' ';
        }
    }
}

