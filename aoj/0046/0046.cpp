#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    double a = 1e100, b = -1e100, t;
    while (scanf("%lf", &t) != EOF) a = min(a, t), b = max(b, t);
    printf("%.6f\n", b-a);
    return 0;
}
