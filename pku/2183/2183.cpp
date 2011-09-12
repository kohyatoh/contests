#include <stdio.h>
#include <map>
using namespace std;

int main() {
    int a;
    map<int, int> m;
    scanf("%d", &a);
    for(int i=0; ; i++) {
        if(m.find(a)!=m.end()) {
            printf("%d %d %d\n", a, i-m[a], i);
            return 0;
        }
        m[a] = i;
        int b = a/10%10000;
        a = b*b%1000000;
    }
}
