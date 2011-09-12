#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, no;
double d;

int main() {
    scanf("%d%lf", &n, &d);
    while(scanf("%d", &no)!=EOF) {
        bool r=true;
        int t=0;
        rep(i, n) {
            char h1, m1, m2, s1, s2;
            scanf(" %c:%c%c:%c%c", &h1, &m1, &m2, &s1, &s2);
            if(h1=='-') r=false;
            else {
                t += ((h1-'0')*60+(m1-'0')*10+(m2-'0'))*60+(s1-'0')*10+(s2-'0');
            }
        }
        if(!r) printf("%3d: -\n", no);
        else {
            int m=(int)(t/d+0.5)/60, s=(int)(t/d+0.5)%60;
            printf("%3d:%2d:%02d min/km\n", no, m, s);
        }
    }
    return 0;
}
