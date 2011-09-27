#include <stdio.h>
#include <iostream>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int N, S, W, Q, a[200000];

Int solve() {
    if(Q==2 || Q==5) {
        Int ans=0, c=0;
        rep(i, N) {
            if(a[i]!=0) c += 1;
            if(a[i]%Q==0) ans += c;
        }
        return ans;
    }
    else {
        Int ans=0, cur=0, p=1;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for(int i=N-1; i>=0; i--) {
            cur = (cur+a[i]*p) % Q;
            p = p*10 % Q;
            if(a[i]!=0) ans += cnt[cur];
            cnt[cur] += 1;
        }
        return ans;
    }
}

int main() {
    for(;;) {
        scanf("%d%d%d%d", &N, &S, &W, &Q);
        if(N==0) return 0;
        int g = S;
        rep(i, N) {
            a[i] = (g/7) % 10;
            if(g%2==0) g = g/2;
            else g = (g/2) ^ W;
        }
        cout << solve() << endl;
    }
}

