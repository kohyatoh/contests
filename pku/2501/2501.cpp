#include <stdio.h>

char buf[1000];

int main() {
    double pos=0, ps=0;
    int pt=0, t, h, m, s, v;
    while(gets(buf)) {
        int c=sscanf(buf, "%d:%d:%d %d", &h, &m, &s, &v);
        t = h*3600+m*60+s;
        pos += ps*(t-pt)/3600;
        pt = t;
        if(c==4) ps=v;
        else printf("%02d:%02d:%02d %.2f km\n", h, m, s, pos);
    }
    return 0;
}
