#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int suit(char c) {
    if(c=='C') return 0;
    if(c=='H') return 1;
    if(c=='S') return 2;
    if(c=='D') return 3;
    return -1;
}
int rank(char c) {
    if(c=='A') return 0;
    if(c=='X') return 9;
    if(c=='J') return 10;
    if(c=='Q') return 11;
    if(c=='K') return 12;
    return c-'1';
}

int T, sc[4], rc[13];
char str[16];

int main() {
    scanf("%d", &T);
    while(T--) {
        rep(i, 4) sc[i]=0;
        rep(i, 13) rc[i]=0;
        rep(i, 5) {
            scanf("%s", str);
            sc[suit(str[0])]++;
            rc[rank(str[1])]++;
        }
        int p=0, is_straight=0, is_flush=0, is_four=0, is_three=0, pair=0;
        rep(i, 10) {
            bool f=true;
            rep(j, 5) if(!rc[(i+j)%13]) f=false;
            if(f) is_straight=1;
        }
        rep(i, 4) if(sc[i]==5) is_flush=1;
        rep(i, 13) {
            if(rc[i]==4) is_four=1;
            if(rc[i]==3) is_three=1;
            if(rc[i]==2) pair++;
        }
        if(is_straight && is_flush) p=1000;
        else if(is_four) p=750;
        else if(is_three && pair==1) p=500;
        else if(is_flush) p=350;
        else if(is_straight) p=250;
        else if(is_three) p=200;
        else if(pair==2) p=100;
        else if(pair==1) p=50;
        printf("%d\n", p);
    }
    return 0;
}
