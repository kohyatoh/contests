#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[200];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", a+i);
    int m=0, c0=0, c1=0;
    rep(i, n) {
        if(a[i]==0) c0++;
        else if(a[i]==1) c1++;
        else a[m++] = a[i];
    }
    sort(a, a+m);
    rep(i, c0) a[m+i] = 0;
    rep(i, c1) a[m+c0+i] = 1;
    if(c0%2) {
        if(c1) swap(a[m+c0-1], a[m+c0]);
        else if(m) {
            const int mini = a[0];
            rep(i, m+c0-2) a[i]=a[i+1];
            a[m+c0-2] = mini;
            m--;
        }
    }
    if(m>=2 && a[m-2]==2 && a[m-1]==3) swap(a[m-2], a[m-1]);
    rep(i, n) printf("%d\n", a[i]);
    return 0;
}
