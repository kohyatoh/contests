#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
pair<int, int> stars[1000];

int indexOf(int x, int y, int l) {
    pair<int, int> *p = lower_bound(stars+l, stars+n, make_pair(x, y));
    if(p==stars+n) return -1;
    if(p->first==x && p->second==y) return p-stars;
    else return -1;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d%d", &stars[i].first, &stars[i].second);
        sort(stars, stars+n);
        int c=0;
        rep(i, n) for(int j=i+1; j<n; j++) {
            int dx=stars[j].first-stars[i].first;
            int dy=stars[j].second-stars[i].second;
            int k, l;
            k=indexOf(stars[i].first-dy, stars[i].second+dx, j+1);
            if(k!=-1) {
                l=indexOf(stars[j].first-dy, stars[j].second+dx, k+1);
                if(l!=-1) c++;
            }
            k=indexOf(stars[i].first+dy, stars[i].second-dx, j+1);
            if(k!=-1) {
                l=indexOf(stars[j].first+dy, stars[j].second-dx, k+1);
                if(l!=-1) c++;
            }
        }
        printf("%d\n", c);
    }
}

