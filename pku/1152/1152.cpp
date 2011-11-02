#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int ctoi(char ch) {
    if('0'<=ch && ch<='9') return ch-'0';
    if('A'<=ch && ch<='Z') return ch-'A'+10;
    if('a'<=ch && ch<='z') return ch-'a'+36;
    return -1;
}

bool check(const string& src, int b) {
    int a = 0;
    rep(i, src.size()) {
        const int k = ctoi(src[i]);
        if(k>=b) return false;
        a = (a*b+k)%(b-1);
    }
    return a==0;
}

int main() {
    string src;
    while(getline(cin, src)) {
        int ans = -1;
        for(int b=2; b<=62; b++) if(check(src, b)) {
            ans = b;
            break;
        }
        if(ans!=-1) printf("%d\n", ans);
        else puts("such number is impossible!");
    }
    return 0;
}

