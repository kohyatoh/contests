#include <stdio.h>

char tbl[128], str[128];

int main() {
    gets(tbl);
    for(char *p=tbl; *p; p++) *p-='a';
    gets(str);
    for(char *p=str; *p; p++) {
        if('A'<=*p && *p<='Z') putchar(tbl[*p-'A']+'A');
        else if('a'<=*p && *p<='z') putchar(tbl[*p-'a']+'a');
        else putchar(*p);
    }
    putchar('\n');
    return 0;
}
