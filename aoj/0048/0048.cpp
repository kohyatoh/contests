#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const char names[11][16] = {
    "light fly",
    "fly",
    "bantam",
    "feather",
    "light",
    "light welter",
    "welter",
    "light middle",
    "middle",
    "light heavy",
    "heavy"
};
const double weights[11] = {
    48.00,
    51.00,
    54.00,
    57.00,
    60.00,
    64.00,
    69.00,
    75.00,
    81.00,
    91.00,
    1e100,
};

int main() {
    double w;
    while (scanf("%lf", &w) != EOF) {
        int ix = 0;
        while (ix < 10 && w > weights[ix]) ix++;
        puts(names[ix]);
    }
    return 0;
}
