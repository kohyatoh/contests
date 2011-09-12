#include <stdio.h>

char ws[7][16] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int ms[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calc(int y, int m, int d) {
    // 1, 1, 1 -> 0
    int ans = 0;
    ans += (y-1)*365 + (y-1)/4 - (y-1)/100 + (y-1)/400;
    for(int i=0; i<m-1; i++) {
        if(i==1 && y%4==0 && (y%100!=0 || y%400==0)) ans++;
        ans += ms[i];
    }
    ans += d-1;
    return ans;
}

int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    int diff = calc(y, m, d)-calc(1900, 1, 1);
    if(diff < 0) puts(ws[6-(-diff-1)%7]);
    else puts(ws[diff%7]);
    return 0;
}
