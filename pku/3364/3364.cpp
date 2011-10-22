#include <stdio.h>
#include <algorithm>
using namespace std;

int f(int n, int m) {
    const int x = (n-7)/2, y = n-7-x;
    const int a = (m-7)/2, b = m-7-a;
    return x*a+y*b;
}

int main() {
    for(;;) {
        int n, m, c;
        scanf("%d%d%d", &n, &m, &c);
        if(n==0 && m==0 && c==0) return 0;
        printf("%d\n", c==1 ? f(n, m) : (n-7)*(m-7)-f(n, m));
    }
}
