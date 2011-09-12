#include <stdio.h>
#include <algorithm>

int main() {
    for(;;) {
        int mw, w, h, cw=0, ch=0, ww=0, wh=0;
        scanf("%d", &mw);
        if(mw==0) return 0;
        for(;;) {
            scanf("%d%d", &w, &h);
            if(w==-1) break;
            if(cw+w>mw) {
                cw = 0;
                ch = wh;
            }
            cw += w;
            ww = std::max(ww, cw);
            wh = std::max(wh, ch+h);
        }
        printf("%d x %d\n", ww, wh);
    }
}
