#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int cross(int x1, int y1, int x2, int y2) { return x1*y2 - x2*y1; }

int n, x[1000], y[1000];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d%d", x+i, y+i);
    int c = 0;
    rep(i, n) for(int j=i+1; j<n; j++) for(int k=j+1; k<n; k++) {
        if(cross(x[j]-x[i], y[j]-y[i], x[k]-x[i], y[k]-y[i])==0) c++;
    }
    printf("%d\n", c);
    rep(i, n) for(int j=i+1; j<n; j++) for(int k=j+1; k<n; k++) {
        if(cross(x[j]-x[i], y[j]-y[i], x[k]-x[i], y[k]-y[i])==0) {
            printf("%d %d %d\n", i+1, j+1, k+1);
        }
    }
    return 0;
}
