#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int target, m, ans;
char num[16];
vector<int> stk, ansv;

int parse(int s, int t) {
    int a = 0;
    for(int i=s; i<t; i++) a = a*10+num[i]-'0';
    return a;
}

void rec(int n, int x) {
    if(x>target) return ;
    stk.push_back(n);
    if(n==m) {
        if(ans<x) {
            ans = x;
            ansv = stk;
        }
        else if(ans==x) {
            ansv.clear();
        }
    }
    else {
        for(int i=n+1; i<=m; i++) {
            rec(i, x+parse(n, i));
        }
    }
    stk.pop_back();
}

int main() {
    for(;;) {
        scanf(" %d%s", &target, num);
        if(target == 0) return 0;
        m = strlen(num);
        ans = -1;
        ansv.clear();
        rec(0, 0);
        if(ans==-1) puts("error");
        else if(ansv.size()==0) puts("rejected");
        else {
            printf("%d", ans);
            rep(k, ansv.size()-1) {
                putchar(' ');
                for(int i=ansv[k]; i<ansv[k+1]; i++) putchar(num[i]);
            }
            putchar('\n');
        }
    }
}
