#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;

int dp[10000][80];
int pre[10000][80];
int ln[10000][80];

int main() {
    string s;
    for(;;) {
        getline(cin, s);
        int N = atoi(s.c_str());
        if(N==0) return 0;
        vector<string> v;
        for(;;) {
            getline(cin, s);
            if(s=="") break;
            stringstream sin(s);
            string ss;
            while(sin>>ss) v.push_back(ss);
        }
        rep(i, v.size()) fill_n(dp[i], 80, -1);
        dp[0][v[0].size()-1] = ln[0][v[0].size()-1] = 0;
        if((int)v[0].size()!=N) { dp[0][N-1] = 500; ln[0][N-1] = 0; }
        rep(i, v.size()-1) {
            dp[i+1][v[i+1].size()-1] = dp[i][N-1];
            pre[i+1][v[i+1].size()-1] = N-1;
            ln[i+1][v[i+1].size()-1] = ln[i][N-1] + 1;
            for(int j=v[i+1].size()+1; j<N; j++) {
                for(int k=0; k<j-(int)v[i+1].size(); k++) if(dp[i][k]!=-1) {
                    int sp = j-v[i+1].size()-k;
                    int d2 = (sp-1)*(sp-1);
                    if(dp[i+1][j]==-1
                        || dp[i+1][j]>dp[i][k]+d2
                        || (dp[i+1][j]==dp[i][k]+d2 && ln[i+1][j]>ln[i][k])
                    ) {
                        dp[i+1][j] = dp[i][k] + d2;
                        pre[i+1][j] = k;
                        ln[i+1][j] = ln[i][k];
                    }
                }
            }
            if(dp[i+1][N-1]==-1
                || dp[i+1][N-1]>dp[i+1][v[i+1].size()-1]+500
                || (dp[i+1][N-1]==dp[i+1][v[i+1].size()-1]+500
                    && ln[i+1][N-1]>ln[i][N-1]+1)
            ) {
                dp[i+1][N-1] = dp[i+1][v[i+1].size()-1] + 500;
                pre[i+1][N-1] = N-1;
                ln[i+1][N-1] = ln[i][N-1] + 1;
            }
        }
        vector<int> spaces;
        int at = N-1;
        for(int i=v.size()-1; i>0; i--) {
            int p = pre[i][at];
            if(p<at) spaces.push_back(at-v[i].size()-p);
            else spaces.push_back(0);
            at = p;
        }
        reverse(spaces.begin(), spaces.end());
        rep(i, v.size()) {
            cout << v[i];
            if(i!=(int)v.size()-1) {
                if(spaces[i]>0) cout << string(spaces[i], ' ');
                else cout << endl;
            }
        }
        cout << endl << endl;
    }
}
