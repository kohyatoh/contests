#include <stdio.h>

int n, x, y;

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &x, &y);
        puts(x<y ? "NO BRAINS" : "MMM BRAINS");
    }
    return 0;
}
