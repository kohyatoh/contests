#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

long long dp[12][3000];

int main() {
    for(;;) {
        int w, h;
        cin >> w >> h;
        if(w==0 && h==0) return 0;
        if(w<h) swap(w, h);
        int nn=1<<h;
        vector<int> v;
        rep(d, nn) {
            bool f=true;
            rep(i, h) if(d&(1<<i)) {
                if((d&(2<<i))==0) { f=false; break; }
                else i++;
            }
            if(f) v.push_back(d);
        }
        rep(i, 12) rep(j, 3000) dp[i][j]=0;
        dp[0][0]=1;
        rep(i, w) rep(j, nn) if(dp[i][j]) rep(k, v.size()) if((j&v[k])==0) {
            dp[i+1][(nn-1)^(j|v[k])]+=dp[i][j];
        }
        cout << dp[w][0] << endl;
    }
}

