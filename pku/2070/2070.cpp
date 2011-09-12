#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

double tbl[3][3] = { {-4.5, 150, 200}, {-6.0, 300, 500}, {-5.0, 200, 300} };
char name[3][20] = { "Wide Receiver", "Lineman", "Quarterback" };
double p[3];

int main() {
    for(;;) {
        rep(i, 3) scanf("%lf", p+i);
        if(p[0]==0 && p[1]==0 && p[2]==0) return 0;
        p[0] = -p[0];
        int c=0;
        rep(k, 3) {
            bool f=true;
            rep(i, 3) if(p[i]<tbl[k][i]) f=false;
            if(f) {
                if(c++) putchar(' ');
                printf("%s", name[k]);
            }
        }
        if(c==0) printf("No positions");
        putchar('\n');
    }
}
