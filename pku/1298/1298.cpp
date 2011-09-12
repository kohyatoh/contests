#include <stdio.h>

char s[300];

int main() {
    for(;;) {
        gets(s);
        if(s[0]=='E') return 0;
        gets(s);
        for(int i=0; s[i]; i++) {
            putchar('A'<=s[i] && s[i]<='Z' ? 'A'+(s[i]-'A'+21)%26 : s[i]);
        }
        putchar('\n');
        gets(s);
    }
}
