#include <stdio.h>

int data[5 * 60];

int decode(char *s) {
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[2] - '0') * 10 + (s[3] - '0');
    return h * 60 + m;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char buf[16];
        scanf("%s", buf);
        int s = decode(buf) / 5;
        int e = (decode(buf + 5) + 4) / 5;
        for (int t = s; t < e; t++) data[t] = 1;
    }
    int p = -1;
    for (int t = 0; t <= 24 * 60 / 5; t++) {
        if (p == -1 && data[t]) {
            p = t;
        }
        if (p != -1 && !data[t]) {
            printf("%02d%02d-%02d%02d\n",
                    p * 5 / 60, p * 5 % 60,
                    t * 5 / 60, t * 5 % 60);
            p = -1;
        }
    }
    return 0;
}
