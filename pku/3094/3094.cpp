#include <stdio.h>

char s[1024];

int main() {
    for(;;) {
        gets(s);
        if(s[0]=='#') return 0;
        int ans = 0;
        for(int i=0; s[i]; i++) {
            if(s[i]!=' ') ans+=(i+1)*(s[i]-'A'+1);
        }
        printf("%d\n", ans);
    }
}
