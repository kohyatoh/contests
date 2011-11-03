#include <stdio.h>
#include <string>
#include <vector>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)

int readTime() {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    return h*3600+m*60+s;
}

void writeTime(int t) {
    printf("%02d:%02d:%02d\n", t/3600, t/60%60, t%60);
}

int t1, t2, t3, t4, n, m, a[100], b[100], c[100];

int main() {
    scanf("%d%d%d%d", &t1, &t2, &t3, &t4);
    scanf("%d", &n);
    rep(i, n) a[i] = readTime();
    a[n] = INF;
    scanf("%d", &m);
    rep(i, m) b[i] = readTime();
    rep(i, m) c[i] = b[i];
    b[m] = INF;
    int l = 0, r = 0;
    while(l<n || r<m) {
        bool takeoff = true;
        for(int i=r; i<m; i++) if(c[i]<=a[l]) takeoff = false;
        if(takeoff) {
            const int t = a[l];
            l++;
            a[l] = max(a[l], t+t1);
            b[r] = max(b[r], t+t2);
        }
        else {
            const int t = b[r];
            r++;
            a[l] = max(a[l], t+t3);
            b[r] = max(b[r], t+t4);
        }
    }
    rep(i, n) writeTime(a[i]);
    rep(i, m) writeTime(b[i]);
    return 0;
}


