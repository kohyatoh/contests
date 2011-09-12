#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const double R=6378.0;
const double pi=3.141592653589793;
inline double sq(double a) { return a*a; }

int n;
double x[200], y[200], z[200];
char name[200][64], a[64], b[64];

int main() {
    map<string, int> ids;
    for(;;) {
        scanf("%s", name[n]);
        if(strcmp(name[n], "#")==0) break;
        double lt, lg;
        scanf("%lf%lf", &lt, &lg);
        lt *= pi/180.0, lg *= pi/180.0;
        x[n] = cos(lt)*sin(lg);
        y[n] = cos(lt)*cos(lg);
        z[n] = sin(lt);
        ids[name[n]] = n;
        n++;
    }
    for(;;) {
        scanf("%s%s", a, b);
        if(strcmp(a, "#")==0 && strcmp(b, "#")==0) return 0;
        printf("%s - %s\n", a, b);
        if(ids.find(a)==ids.end() || ids.find(b)==ids.end()) puts("Unknown");
        else {
            const int aix=ids[a], bix=ids[b];
            double d2=sq(x[aix]-x[bix])+sq(y[aix]-y[bix])+sq(z[aix]-z[bix]);
            double theta=acos(1.0-d2/2.0);
            printf("%.0f km\n", theta*R);
        }
        puts("");
    }
}

