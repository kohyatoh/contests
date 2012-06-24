#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define N (60000)
int pt[N];

int main() {
    for (int i = 2; i < N; i++) if (pt[i] == 0) {
        for (int j = i+i; j < N; j+=i) pt[j] = i;
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        int lo = n-1, hi = n+1;
        while (pt[lo]) lo--;
        while (pt[hi]) hi++;
        printf("%d %d\n", lo, hi);
    }
    return 0;
}
