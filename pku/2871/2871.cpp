#include <stdio.h>

int main() {
    double f, t;
    scanf("%lf", &f);
    for(;;) {
        scanf("%lf", &t);
        if(t>400) break;
        printf("%.2f\n", t-f);
        f = t;
    }
    puts("End of Output");
    return 0;
}
