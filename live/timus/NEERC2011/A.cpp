#include <stdio.h>

int main() {
    int h, t, v, x;
    scanf("%d%d%d%d", &h, &t, &v, &x);
    if(x*t<h) {
        printf("%.9f %.9f\n", (double)(h-x*t)/(v-x), (double)t);
    }
    else {
        printf("%.9f %.9f\n", 0.0, (double)h/x);
    }
    return 0;
}
