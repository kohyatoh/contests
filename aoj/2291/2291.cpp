#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

#define MOD (1000000009LL)
#define MAXN (200000)
#define MAXE (500000)

int N, M;
int dig[MAXN], is[MAXN];
int E, u[MAXE], v[MAXE], next[MAXE], head[MAXN];

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &N, &M);
    rep(_, M) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        dig[x]++, dig[y]++;
        u[E]=x; v[E]=y; next[E]=head[u[E]]; head[u[E]]=E; E++;
        u[E]=y; v[E]=x; next[E]=head[u[E]]; head[u[E]]=E; E++;
    }
    rep(i, N) {
        is[i] = 1;
        for(int x=head[i]; x!=-1; x=next[x]) if(dig[v[x]]<dig[i]) {
            is[i] = 0;
            break;
        }
    }
    Int ansm = 0, answ = 1;
    rep(i, N) if(is[i]) {
        int c = 0;
        for(int x=head[i]; x!=-1; x=next[x]) if(dig[v[x]]==dig[i]) {
            is[v[x]] = 0;
            c++;
        }
        ansm += 1;
        answ = answ*(c+1)%MOD;
    }
    cout << ansm << endl;
    cout << answ << endl;
    return 0;
}
