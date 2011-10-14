#include <stdio.h>
#include <ctype.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    char b[10];
    int f, t;
    while(scanf("%s%d%d", b, &f, &t)!=EOF) {
        long long a = 0;
        for(int i=0; b[i]; i++) {
            const int k = isdigit(b[i]) ? b[i]-'0' : b[i]-'A'+10;
            a = (a*f)+k;
        }
        string r;
        while(a>0) {
            const int d = a%t;
            a /= t;
            r += (char)(d<10 ? d+'0' : d-10+'A');
        }
        reverse(r.begin(), r.end());
        if(r.size()>7) r = "ERROR";
        printf("%7s\n", r.c_str());
    }
    return 0;
}
