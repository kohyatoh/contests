#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int k = 1, s = 1;
    while(s<n || s%2!=n%2) s += ++k;
    printf("%d\n", k);
    return 0;
}
