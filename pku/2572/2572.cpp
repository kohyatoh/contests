#include <stdio.h>
#include <string.h>
#include <algorithm>

char s[100];

int main() {
    while(strcmp(s, "0=0+0")) {
        gets(s);
        std::reverse(s, s+strlen(s));
        char *p=s;
        int c=atoi(p);
        while(*p++!='=');
        int b=atoi(p);
        while(*p++!='+');
        int a=atoi(p);
        puts(a+b==c ? "True" : "False");
    }
}
