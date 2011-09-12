#include <stdio.h>
#include <algorithm>

double d[500];

int main() {
    for(int i=1; i<500; i++) d[i]=d[i-1]+1./(i+1);
    for(;;) {
        double c;
        scanf("%lf", &c);
        if(c==0) return 0;
        printf("%d card(s)\n", std::lower_bound(d, d+500, c)-d);
    }
}

