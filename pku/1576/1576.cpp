#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char buf[400], board[400], cards[200][16];
int loc[4];

int main() {
    for(;;) {
        gets(buf);
        int p, l, n;
        sscanf(buf, "%d%d%d", &p, &l, &n);
        if(p==0) return 0;
        gets(board);
        rep(i, n) gets(cards[i]);
        rep(i, 4) loc[i]=-1;
        int ans=0, drawn=0;
        rep(i, n) {
            drawn++;
            rep(j, 2) if(cards[i][j]>0) {
                do { loc[i%p]++; } while(loc[i%p]<l && board[loc[i%p]]!=cards[i][j]);
            }
            if(loc[i%p]>=l-1) { ans=i%p+1; break; }
        }
        if(ans==0) printf("No player won after %d cards.\n", drawn);
        else printf("Player %d won after %d cards.\n", ans, drawn);
    }
}

