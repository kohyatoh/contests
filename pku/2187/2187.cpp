#include <stdio.h>
#include <complex>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

typedef int number;
typedef complex<number> P;
#define X(p) real(p)
#define Y(p) imag(p)
namespace std {
    bool operator<(const P& a, const P& b) {
        return X(a)!=X(b) ? X(a)<X(b) : Y(a)<Y(b);
    }
}

number cross(const P& a, const P& b) { return imag(conj(a)*b); }
number dot(const P& a, const P& b) { return real(conj(a)*b); }
int ccw(const P& a, P b, P c) {
    b-=a, c-=a;
    if(cross(b, c)>0) return 1;
    if(cross(b, c)<0) return -1;
    if(dot(b, c)<0) return 2;
    if(norm(b)<norm(c)) return -2;
    return 0;
}
vector<P> convex_hull(vector<P> ps) {
    int n=ps.size(), k=0;
    sort(ps.begin(), ps.end());
    vector<P> v(2*n);
    for(int i=0; i<n; v[k++]=ps[i++]) {
        while(k>1 && ccw(v[k-2], v[k-1], ps[i])<=0) k--;
    }
    for(int i=n-2, t=k; i>=0; v[k++]=ps[i--]) {
        while(k>t && ccw(v[k-2], v[k-1], ps[i])<=0) k--;
    }
    v.resize(k-1);
    return v;
}
number convex_diameter(const vector<P>& pt) {
    const int n=pt.size();
    int is=0, js=0;
    for(int i=1; i<n; i++) {
        if(Y(pt[i])>Y(pt[is])) is=i;
        if(Y(pt[i])<Y(pt[js])) js=i;
    }
    number maxd=norm(pt[is]-pt[js]);
    int i=is, j=js, maxi=is, maxj=js;
    do {
        if(cross(pt[(i+1)%n]-pt[i], pt[(j+1)%n]-pt[j])>=0) j=(j+1)%n;
        else i=(i+1)%n;
        if(norm(pt[i]-pt[j]) > maxd) {
            maxd = norm(pt[i]-pt[j]);
            maxi=i, maxj=j;
        }
    } while(i!=is || j!=js);
    return maxd; /* farthest pair is (maxi, maxj). */
}

int main() {
    int n, x, y;
    scanf("%d", &n);
    vector<P> p;
    rep(i, n) {
        scanf("%d%d", &x, &y);
        p.push_back(P(x, y));
    }
    p = convex_hull(p);
    printf("%d\n", convex_diameter(p));
    return 0;
}
