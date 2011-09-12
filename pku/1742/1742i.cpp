#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, a[200], c[200];
int dp[100010], dc[100010], next[100010], prev[100010];
int qh, qt, q[100010];

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, n) scanf("%d", a+i);
        rep(i, n) scanf("%d", c+i);
        rep(i, m+1) dp[i]=0;
        dp[0]=1;
        next[0]=m+1;
        int ans=0, mm=0, mmm=m*0.15;
        int lim, col, k, i, r, t;
        for(i=0; i<n && ans<mmm; i++) {
            col=i+2;
            if(mm<m) mm += a[i]*c[i];
            qh=qt=0;
            for(k=0,r=a[i]; r<=m || qh<qt; k=next[k],r=k+a[i]) {
                if(r<=m && dp[r]==0) {
                    if(dp[k]<col) {
                        ans++;
                        q[qt++] = r;
                        dp[r] = col;
                        dc[r] = 1;
                    }
                    else if(dc[k]<c[i]) {
                        ans++;
                        q[qt++] = r;
                        dp[r] = col;
                        dc[r] = dc[k]+1;
                    }
                }
                if(qh<qt && q[qh]<next[k]) {
                    t=q[qh++];
                    next[t]=next[k];
                    next[k]=t;
                }
            }
        }
        if(i<n) {
            r=0;
            for(k=0; k<=m; k++) {
                prev[k]=r;
                if(dp[k]==0) {
                    next[r]=k;
                    r=k;
                }
            }
            next[r]=m+1;
            r=m+1;
            for(k=m; k>=0; k--) {
                next[k]=r;
                if(dp[k]==0) {
                    prev[r]=k;
                    r=k;
                }
            }
            prev[r]=0;
        }
        for(; i<n; i++) {
            col=i+2;
            if(mm<m) mm += a[i]*c[i];
            lim = min(m, mm)+1;
            k=a[i];
            while(k<=m && dp[k]) k=next[k];
            r=a[i];
            while(r<k) {
                t=next[r];
                next[r]=k;
                r=t;
            }
            while(k<lim) {
                if(dp[k-a[i]]) {
                    if(dp[k-a[i]]<col) {
                        ans++;
                        dp[k] = col;
                        dc[k] = 1;
                        next[prev[k]]=next[k];
                        prev[next[k]]=prev[k];
                    }
                    else if(dc[k-a[i]]<c[i]) {
                        ans++;
                        dp[k] = col;
                        dc[k] = dc[k-a[i]]+1;
                        next[prev[k]]=next[k];
                        prev[next[k]]=prev[k];
                    }
                }
                k=next[k];
            }
        }
        printf("%d\n", ans);
    }
}
