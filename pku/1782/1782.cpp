#include <stdio.h>

void put(char ch, int k) {
    if(k==1 && ch!='1') putchar(ch);
    else {
        putchar('0'+k);
        putchar(ch);
    }
}

int main() {
    int k=0, pre=-1;
    int ch;
    bool es = false;
    while((ch=getchar())!=EOF) {
        if(pre!=-1 && (ch!=pre || k==9)) {
            if(es != (k==1)) putchar('1');
            es = k==1;
            put(pre, k);
            k = 0;
        }
        pre = ch;
        k++;
        if(ch=='\n') {
            if(es) putchar('1');
            putchar('\n');
            k = 0, pre = -1, es = false;
        }
    }
    return 0;
}
