#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, w, h;
pair<int, int> p[500000];
#define X(i) p[i].first
#define Y(i) p[i].second

int main() {
    scanf("%d%d%d", &n, &w, &h);
    rep(i, n) scanf("%d%d", &p[i].first, &p[i].second);
    sort(p, p+n);
    int ans=0;
    for(int i=0, j=0, k=0, l=0; i<n; i++) {
        j = max(j, i);
        while(j<n && (X(j)==X(i) && Y(j)<Y(i)+h)) j++;
        if(j==n) break;
        if(X(j)!=X(i) || Y(j)!=Y(i)+h) continue;
        k = max(k, j);
        while(k<n && X(k)<X(i)+w) k++;
        while(k<n && X(k)==X(i)+w && Y(k)<Y(i)) k++;
        if(k==n) break;
        if(X(k)!=X(i)+w || Y(k)!=Y(i)) continue;
        l = max(l, k);
        while(l<n && X(l)==X(i)+w && Y(l)<Y(i)+h) l++;
        if(X(l)!=X(i)+w || Y(l)!=Y(i)+h) continue;
        if(l==n) break;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
