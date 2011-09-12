#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

string memo[100];

string cantor(int r) {
    if(memo[r].size()) return memo[r];
    if(r==0) return memo[r]="-";
    int k=1;
    rep(i, r-1) k*=3;
    return memo[r]=cantor(r-1)+string(k, ' ')+cantor(r-1);
}

int main() {
    int n;
    while(cin>>n) cout<<cantor(n)<<endl;
    return 0;
}
