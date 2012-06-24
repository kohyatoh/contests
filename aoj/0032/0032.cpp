#include <stdio.h>
typedef long long Int;

bool is_rect(Int x, Int y, Int t) {
    return t*t == x*x+y*y;
}

bool is_loze(Int x, Int y, Int t) {
    return x == y;
}

int main() {
    int a = 0, b = 0;
    int x, y, t;
    while (scanf("%d,%d,%d", &x, &y, &t) != EOF) {
        if (is_rect(x, y, t)) a++;
        if (is_loze(x, y, t)) b++;
    }
    printf("%d\n", a);
    printf("%d\n", b);
    return 0;
}
