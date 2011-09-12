#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

pair<double, int> a[65536];
int n, s, id, l;
double f;

int select(int k) {
    int l=0, r=n-1;
    while(l<r) {
        double p=a[(l+r)/2].first;
        int i=l-1, j=r+1;
        for(;;) {
            while(a[++i].first<p);
            while(a[--j].first>p);
            if(i>=j) break;
            std::swap(a[i], a[j]);
        }
        if(i==j && i==k) return a[k].second;
        if(k<i) r=i-1;
        else l=j+1;
    }
    return a[k].second;
}

int main() {
    while(scanf("%d", &n)!=EOF) {
        rep(i, n) {
            scanf("%d%d%lf", &id, &l, &f);
            a[i].first = l/f;
            a[i].second = id;
        }
        scanf("%d", &s);
        printf("%d\n", select(s-1));
    }
    return 0;
}
