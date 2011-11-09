#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, c, a[60000], mx[300], mn[300];

int query(int k) {
    const int b = k/m, l = b*m, r = min(n, (b+1)*m);
    int la = -1, ra = n;
    for(int i=k; i>=l; i--) if(a[i]) { la = i; break; }
    if(la==-1) for(int i=b-1; i>=0; i--) if(mx[i]>=0) { la = mx[i]; break; }
    for(int i=k; i<r; i++) if(a[i]) { ra = i; break; }
    if(ra==n) for(int i=b+1; i<c; i++) if(mn[i]>=0) { ra = mn[i]; break; }
    return max(0, ra-la-1);
}

int main() {
    int Q;
    scanf("%d%d", &n, &Q);
    m = max(20, (int)sqrt((double)n));
    c = (n+m-1)/m;
    memset(mx, -1, sizeof(mx));
    memset(mn, -1, sizeof(mn));
    vector<int> stk;
    while(Q--) {
        char op;
        scanf(" %c", &op);
        if(op=='Q') {
            int k;
            scanf("%d", &k);
            k--;
            printf("%d\n", query(k));
        }
        else {
            if(op=='D') {
                int k;
                scanf("%d", &k);
                k--;
                stk.push_back(k);
                a[k] = 1;
                const int b = k/m;
                if(mx[b]==-1 || mx[b]<k) mx[b] = k;
                if(mn[b]==-1 || mn[b]>k) mn[b] = k;
            }
            else {
                const int k = stk.back();
                stk.pop_back();
                a[k] = 0;
                const int b = k/m;
                if(mx[b]==k && mn[b]==k) mx[b] = mn[b] = -1;
                else if(mx[b]==k) {
                    for(int i=mx[b]; ; i--) if(a[i]) { mx[b]=i; break; }
                }
                else if(mn[b]==k) {
                    for(int i=mn[b]; ; i++) if(a[i]) { mn[b]=i; break; }
                }
            }
        }
    }
    return 0;
}
