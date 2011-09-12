#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

double x[4], y[4];

int main() {
    while(scanf("%lf%lf", x, y)!=EOF) {
        rep(i, 3) scanf("%lf%lf", x+i+1, y+i+1);
        double sx=0, sy=0;
        rep(i, 4) sx+=x[i], sy+=y[i];
        rep(i, 4) rep(j, i) if(x[i]==x[j] && y[i]==y[j]) {
            printf("%.3f %.3f\n", sx-3*x[i], sy-3*y[i]);
            goto fin;
        }
fin:;
    }
    return 0;
}
