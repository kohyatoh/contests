#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define INF (2000000000)

int M, N, f[100][500], d[100][500];
struct node {
    int m, n, c;
    node(int m, int n, int c) : m(m), n(n), c(c) {}
};
bool operator<(const node& l, const node& r) { return l.c>r.c; }

priority_queue<node> q;
void push(int m, int n, int c) {
    if(d[m][n]>c+f[m][n]) {
        d[m][n]=c+f[m][n];
        q.push(node(m, n, d[m][n]));
    }
}

void print(int m, int n) {
    if(m>0) {
        if(d[m][n]-f[m][n]==d[m-1][n]) print(m-1, n);
        else if(n>0 && d[m][n]-f[m][n]==d[m][n-1]) print(m, n-1);
        else print(m, n+1);
    }
    printf("%d\n", n+1);
}

int main() {
    scanf("%d%d", &M, &N);
    rep(i, M) rep(j, N) scanf("%d", f[i]+j);
    rep(i, M) rep(j, N) d[i][j]=INF;
    rep(i, N) push(0, i, 0);
    while(!q.empty()) {
        node v=q.top();
        q.pop();
        if(d[v.m][v.n]<v.c) continue;
        if(v.m==M-1) {
            print(v.m, v.n);
            break;
        }
        push(v.m+1, v.n, v.c);
        if(v.n>0) push(v.m, v.n-1, v.c);
        if(v.n<N-1) push(v.m, v.n+1, v.c);
    }
    return 0;
}
