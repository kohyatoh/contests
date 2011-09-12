#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int x, n, a[100];

int main() {
    for(;;) {
        scanf("%d%d", &x, &n);
        if(x==0 && n==0) return 0;
        rep(i, n) scanf("%d", a+i);
        sort(a, a+n, greater<int>());
        set<vector<int> > ans;
        int nn=1<<n;
        rep(d, nn) {
            int s=0;
            rep(i, n) if(d&(1<<i)) s+=a[i];
            if(s==x) {
                vector<int> v;
                rep(i, n) if(d&(1<<i)) v.push_back(a[i]);
                ans.insert(v);
            }
        }
        printf("Sums of %d:\n", x);
        if(ans.size()==0) printf("NONE\n");
        for(set<vector<int> >::reverse_iterator it=ans.rbegin(); it!=ans.rend(); it++) {
            rep(i, it->size()) {
                printf("%d%c", (*it)[i], i<(int)it->size()-1?'+':'\n');
            }
        }
    }
}

