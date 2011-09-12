#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

double a[5];
char t[5];
char buf[200];
int of[5] = {9, 4, 4, 4, 7};

int main() {
    for(;;) {
        gets(buf);
        if(*buf=='-') return 0;
        double f=0, s=0;
        do {
            sscanf(buf, "%lf %c%lf %c%lf %c%lf %c%lf %c", a, t, a+1, t+1, a+2, t+2, a+3, t+3, a+4, t+4);
            double c=0;
            int p=0;
            rep(i, 5) if(t[i]=='g') a[i]*=of[i], t[i]='C';
            rep(i, 5) if(t[i]=='C') c+=a[i];
            rep(i, 5) if(t[i]=='%') p+=a[i];
            double r=c/(100.0-p);
            rep(i, 5) if(t[i]=='%') a[i]*=r;
            rep(i, 5) s+=a[i];
            f+=a[0];
            gets(buf);
        } while(*buf!='-');
        printf("%.0f%\n", f/s*100);
    }
}

