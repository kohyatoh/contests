#include <stdio.h>

int main() {
    bool some = false;
    int x;
    double w, h;
    while (scanf("%d,%lf,%lf", &x, &w, &h) != EOF) {
        if (w >= 25*h*h) {
            printf("%d\n", x);
            some = true;
        }
    }
    if (!some) puts("該当なし");
    return 0;
}
