#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define QSIZE (2000)

int n, tid[1000000];
int q[QSIZE], qi, qe;
int inq[1000], tq[1000][QSIZE], tqi[1000], tqe[1000];
char com[100];

int main() {
    for(int nth=1;; nth++) {
        scanf("%d", &n);
        if(n==0) return 0;
        printf("Scenario #%d\n", nth);
        qi=qe=0;
        rep(i, n) tqi[i]=tqe[i]=inq[i]=0;
        rep(i, n) {
            int m, x;
            scanf("%d", &m);
            rep(j, m) {
                scanf("%d", &x);
                tid[x]=i;
            }
        }
        for(;;) {
            scanf(" %s", com);
            if(com[0]=='S') break;
            else if(com[0]=='D') {
                int ix=q[qi];
                printf("%d\n", tq[ix][tqi[ix]]);
                tqi[ix] = (tqi[ix]+1)%QSIZE;
                if(tqi[ix]==tqe[ix]) {
                    inq[ix] = 0;
                    qi = (qi+1)%QSIZE;
                }
            }
            else {
                int x;
                scanf("%d", &x);
                int ix=tid[x];
                tq[ix][tqe[ix]] = x;
                tqe[ix] = (tqe[ix]+1)%QSIZE;
                if(!inq[ix]) {
                    inq[ix] = 1;
                    q[qe] = ix;
                    qe = (qe+1)%QSIZE;
                }
            }
        }
        printf("\n");
    }
}
