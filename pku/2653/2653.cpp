#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, id[1000];
double sx[1000], sy[1000], tx[1000], ty[1000], ax, ay, bx, by;

double cross(double x1, double y1, double x2, double y2) { return x1*y2-x2*y1; }
bool crossing(int k) {
    return cross(tx[k]-sx[k], ty[k]-sy[k], ax-sx[k], ay-sy[k])
         * cross(tx[k]-sx[k], ty[k]-sy[k], bx-sx[k], by-sy[k])<0
        && cross(bx-ax, by-ay, sx[k]-ax, sy[k]-ay)
         * cross(bx-ax, by-ay, tx[k]-ax, ty[k]-ay)<0;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        m = 0;
        rep(x, n) {
            scanf("%lf%lf%lf%lf", &ax, &ay, &bx, &by);
            int k=0;
            rep(i, m) if(!crossing(i)) {
                sx[k]=sx[i], sy[k]=sy[i], tx[k]=tx[i], ty[k]=ty[i], id[k]=id[i];
                k++;
            }
            sx[k]=ax, sy[k]=ay, tx[k]=bx, ty[k]=by, id[k]=x+1;
            m = k+1;
        }
        printf("Top sticks:");
        rep(i, m) printf(" %d%c", id[i], i==m-1 ? '.' : ',');
        printf("\n");
    }
}

