#include <stdio.h>
#include <math.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
double r, x[100], y[100];
double pi=atan2(0, -1);

int main() {
	scanf("%d%lf", &n, &r);
	rep(i, n) scanf("%lf%lf", x+i, y+i);
	double ans=2*pi*r;
	rep(i, n) ans+=hypot(x[i]-x[(i+1)%n], y[i]-y[(i+1)%n]);
	printf("%.2f\n", ans);
	return 0;
}

