#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int f(int n, char c) {
    if(n<=2) {
        if(c=='A' || c=='D') return 0;
        return 1;
    }
    else if(n<=20) {
        if(c=='A' || c=='F') return 0;
        return 1;
    }
    else {
        if(c=='A' || c=='K') return 0;
        if(c=='C' || c=='D' || c=='G' || c=='H') return 1;
        return 2;
    }
}

const char of[3][16] = { "window", "aisle", "neither" };

int main() {
    int n;
    char c;
    scanf("%d%c", &n, &c);
    puts(of[f(n, c)]);
    return 0;
}


