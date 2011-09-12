#include <stdio.h>
#include <ctype.h>

int main() {
    bool inSentence=false, inWord=false;
    int ch, cnt=0;
    while((ch=getchar()) != EOF) {
        if(!inSentence && islower(ch)) cnt++;
        if(inWord && isupper(ch)) cnt++;
        if(isalpha(ch)) inSentence = inWord = true;
        else inWord = false;
        if(ch=='.' || ch=='!' || ch=='?') inSentence = false;
    }
    printf("%d\n", cnt);
    return 0;
}
