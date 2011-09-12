#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

double x[2][3], y[2][3];
int s[2];

int main() {
    for(;;) {
        rep(i, 2) rep(j, 3) scanf("%lf%lf", x[i]+j, y[i]+j);
        if(x[0][0]==-100) return 0;
        rep(i, 2) {
            s[i] = 0;
            rep(j, 3) {
                double d2=x[i][j]*x[i][j]+y[i][j]*y[i][j];
                if(d2<=9) s[i] += 100;
                else if(d2<=36) s[i] += 80;
                else if(d2<=81) s[i] += 60;
                else if(d2<=144) s[i] += 40;
                else if(d2<=225) s[i] += 20;
            }
        }
        printf("SCORE: %d to %d, ", s[0], s[1]);
        if(s[0]==s[1]) printf("TIE.\n");
        else printf("PLAYER %d WINS.\n", s[0]>s[1]?1:2);
    }
}
