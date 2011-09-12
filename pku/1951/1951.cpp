#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char s[80];
int used[128];

int main() {
    used['A'] = used['E'] = used['I'] = used['O'] = used['U'] = 1;
    gets(s);
    int c=0, space=0;
    for(int i=0; s[i]!=0; i++) {
        if(s[i]!=' ') {
            if(used[s[i]]) continue;
            if('A'<=s[i] && s[i]<='Z') used[s[i]]=1;
            if(space && 'A'<=s[i] && s[i]<='Z') putchar(' ');
            putchar(s[i]);
            space=0;
            c++;
        }
        else {
            if(c) space=1;
        }
    }
    putchar('\n');
    return 0;
}
