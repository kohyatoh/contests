#include <stdio.h>

void print(int s) {
    printf("%02d:%02d:%02d\n", s/60/60, s/60%60, s%60);
}

int main() {
    for (;;) {
        int h, m, s;
        scanf("%d%d%d", &h, &m, &s);
        if (h == -1 && m == -1 && s == -1) return 0;
        const int r = 120*60 - h*60*60 - m*60 - s;
        print(r);
        print(r*3);
    }
}
