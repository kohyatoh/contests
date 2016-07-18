#include <stdio.h>

const char *dirs[] = {
    "N", "NNE", "NE", "ENE",
    "E", "ESE", "SE", "SSE",
    "S", "SSW", "SW", "WSW",
    "W", "WNW", "NW", "NNW",
};

int power(int dism) {
    int dis = dism / 6 + (dism % 6 >= 3);
    if (dis <= 2) return 0;
    if (dis <= 15) return 1;
    if (dis <= 33) return 2;
    if (dis <= 54) return 3;
    if (dis <= 79) return 4;
    if (dis <= 107) return 5;
    if (dis <= 138) return 6;
    if (dis <= 171) return 7;
    if (dis <= 207) return 8;
    if (dis <= 244) return 9;
    if (dis <= 284) return 10;
    if (dis <= 326) return 11;
    return 12;
}

const char *direction(int deg, int pow) {
    if (pow == 0) return "C";
    for (int i = 0; i < 16; i++) {
        if (deg * 10 < 1125 + 2250 * i) return dirs[i];
    }
    return "N";
}

int main() {
    int deg, dis;
    scanf("%d%d", &deg, &dis);
    int pow = power(dis);
    printf("%s %d\n", direction(deg, pow), pow);
    return 0;
}
