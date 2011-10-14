#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int N;
    scanf("%d", &N);
    vector<int> a3;
    for(int i=2; i<=N; i++) a3.push_back(i*i*i);
    vector<vector<int> > ans;
    for(int i=2; i<=N; i++) {
        for(int j=2; j<=i; j++) {
            for(int k=2; k<=j; k++) {
                const int x = i*i*i+j*j*j+k*k*k;
                const int ix = lower_bound(a3.begin(), a3.end(), x)-a3.begin();
                if(ix<(int)a3.size() && a3[ix]==x) {
                    vector<int> v;
                    v.push_back(2+ix);
                    v.push_back(k);
                    v.push_back(j);
                    v.push_back(i);
                    ans.push_back(v);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    rep(i, ans.size()) {
        printf("Cube = %d, Triple = (%d,%d,%d)\n",
                ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
    }
    return 0;
}
