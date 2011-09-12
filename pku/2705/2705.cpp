#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

int s, w[200];

int main() {
    for(int _t=0;; _t++) {
        scanf("%d", &s);
        if(s==-1) return 0;
        deque<int> q;
        int cur = 0;
        for(;;) {
            char op;
            scanf(" %c", &op);
            if(op=='E') break;
            int id;
            scanf("%d", &id);
            if(op=='A') {
                scanf("%d", w+id);
                q.push_front(id);
                cur += w[id];
                while(cur>s) {
                    cur -= w[q.back()];
                    q.pop_back();
                }
            }
            else if(op=='R') {
                foreach(it, q) if(*it==id) {
                    q.erase(it);
                    cur -= w[id];
                    break;
                }
            }
        }
        printf("PROBLEM %d:", _t+1);
        rep(i, q.size()) printf(" %d", q[i]);
        printf("\n");
    }
}


