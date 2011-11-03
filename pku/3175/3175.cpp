#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int L, f;
    scanf("%d%d", &L, &f);
    double ex = 1;
    while(L--) ex *= 10;
    for(int k=1; ; k++) {
        const double x = k+f/ex;
        const long long sq = x*x+0.5;
        const double r = sqrt((double)sq);
        const int rem = ex*(r-(int)r);
        if(rem==f) {
            cout << sq << endl;
            return 0;
        }
    }
}
