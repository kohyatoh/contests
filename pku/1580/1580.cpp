#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }

int calc(string a, string b) {
    int ans = 0;
    rep(i, a.size()) {
        const int m = min(a.size()-i, b.size());
        int c = 0;
        rep(j, m) if(a[i+j]==b[j]) c++;
        ans = max(ans, c);
    }
    return ans;
}

int main() {
    string a, b;
    for(;;) {
        cin >> a;
        if(a=="-1") return 0;
        cin >> b;
        const int x = max(calc(a, b), calc(b, a))*2;
        const int y = a.size()+b.size();
        printf("appx(%s,%s) = ", a.c_str(), b.c_str());
        const int g = gcd(x, y);
        if(g==y) printf("%d\n", x/y);
        else printf("%d/%d\n", x/g, y/g);
    }
}
