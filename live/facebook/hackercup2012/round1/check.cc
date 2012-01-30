#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define MOD (4207849484LL)
typedef long long Int;

void msort(int *a, int n) {
    if (n <= 1) return;
    const int m = n / 2;
    msort(a, m);
    msort(a+m, n-m);
    vector<int> rs;
    int *p = a, *q = a+m;
    while (p < a+m && q < a+n) {
        if (*p < *q) {
            putchar('1');
            rs.push_back(*p++);
        }
        else {
            putchar('2');
            rs.push_back(*q++);
        }
    }
    while (p < a+m) rs.push_back(*p++);
    while (q < a+n) rs.push_back(*q++);
    rep (i, n) a[i] = rs[i];
}

int a[10000];

int main() {
    int n;
    cin >> n;
    rep (i, n) cin >> a[i];
    msort(a, n);
    putchar('\n');
    return 0;
}


