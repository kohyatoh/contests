#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
double wx[20], wy[20][4];
double d[100][100];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==-1) return 0;
        vector<double> vx, vy;
        vx.push_back(0), vy.push_back(5);
        rep(i, n) {
            scanf("%lf", wx+i);
            rep(j, 4) scanf("%lf", wy[i]+j);
            rep(j, 4) vx.push_back(wx[i]), vy.push_back(wy[i][j]);
        }
        vx.push_back(10), vy.push_back(5);
        int m=vx.size();
        rep(i, m) rep(j, i) d[j][i]=1000;
        rep(i, m) rep(j, i) if(vx[j]<vx[i]) {
            d[j][i]=hypot(vx[i]-vx[j], vy[i]-vy[j]);
            rep(k, n) if(vx[j]<wx[k] && wx[k]<vx[i]) {
                double a=wx[k]-vx[j], b=vx[i]-wx[k];
                double h=(vy[j]*b+vy[i]*a)/(a+b);
                if((h<=wy[k][0] || wy[k][1]<=h)
                    && (h<=wy[k][2] || wy[k][3]<=h)) {
                    d[j][i]=1000;
                    break;
                }
            }
        }
        rep(i, m) rep(j, i) d[0][i]=min(d[0][i], d[0][j]+d[j][i]);
        printf("%.2f\n", d[0][m-1]);
    }
}

