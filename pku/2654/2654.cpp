#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k, p1, p2, m1, m2, w[100], l[100];
char b1[16], b2[16];

int f(char *p) {
    if(*p=='r') return 0;
    if(*p=='s') return 1;
    return 2;
}

int main() {
    for(int q=0;; q++) {
        if(q) printf("\n");
        scanf("%d", &n);
        if(n==0) return 0;
        scanf("%d", &k);
        memset(w, 0, sizeof(w));
        memset(l, 0, sizeof(l));
        rep(i, k*n*(n-1)/2) {
            scanf("%d %s %d %s", &p1, b1, &p2, b2);
            p1--, p2--;
            m1=f(b1), m2=f(b2);
            if(m1!=m2) {
                if((m1+1)%3==m2) w[p1]++, l[p2]++;
                else w[p2]++, l[p1]++;
            }
        }
        rep(i, n) {
            if(w[i]+l[i]==0) printf("-\n");
            else printf("%.3f\n", 1.0*w[i]/(w[i]+l[i]));
        }
    }
}
