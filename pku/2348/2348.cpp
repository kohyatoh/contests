#include <stdio.h>
#include <algorithm>

char name[][10] = {"Stan", "Ollie"};

int win(int a, int b) {
    if(a<b) std::swap(a, b);
    if(a/b>=2 || a%b==0) return 0;
    else return 1^win(b, a-b);
}

int main() {
    for(;;) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a==0 && b==0) return 0;
        printf("%s wins\n", name[win(a, b)]);
    }
}

