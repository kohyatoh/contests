#include <stdio.h>
#include <string.h>
#include <utility>
#include <algorithm>
using namespace std;

char buf[1024];
int n, d, w;
char names[100][100];
pair<int, int> v[100];

int main() {
    int c=0;
    while(gets(buf)) {
        if(strcmp(buf, "START")) break;
        if(c++) puts("");
        n = 0;
        for(;;) {
            gets(buf);
            if(strcmp(buf, "END")==0) break;
            sscanf(buf, "%s%d%d", names[n], &d, &w);
            v[n].first = w-d;
            v[n].second = n;
            n++;
        }
        sort(v, v+n);
        for(int i=n-1; i>=0; i--) puts(names[v[i].second]);
    }
    return 0;
}
