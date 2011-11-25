#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N (100000)
#define HASH_SIZE (50001)
#define P (1007)

unsigned int hash_size;
int hash_head[HASH_SIZE];
unsigned int hash_list_body[N][32];
int hash_list_next[N];

int is_same_bits(int* l, int* r) {
    register unsigned int i;
    for(i=0; i<32; i++) if(l[i]!=r[i]) return 0;
    return 1;
}

int hash_value(int* b) {
    register unsigned int i;
    register unsigned int h=0;
    //for(i=0; i<32; i++) h = (h*P+b[i])%HASH_SIZE;
    for(i=0; i<32; i++) h += b[i];
    h %= HASH_SIZE;
    return h;
}

void hash_insert(int i) {
    unsigned int h = hash_value(hash_list_body[i]);
    register int* p = hash_head+h;
    while(*p!=-1) {
        if(is_same_bits(hash_list_body[i], hash_list_body[*p])) return ;
        p = hash_list_next+*p;
    }
    hash_list_next[i] = -1;
    *p = i;
    hash_size++;
}

#define BUFSIZE (120000)
#define MINREAD (2048)
unsigned char buf[BUFSIZE], *buf_end;
int ended=0;

unsigned char* fetch(unsigned char* cur) {
    if(ended) return cur;
    if(cur==buf+BUFSIZE) cur=buf_end=buf;
    else if(buf+BUFSIZE<cur+MINREAD) {
        // move buffer
        int size = buf_end-cur;
        int *p=(int*)(cur-((int)cur)%4), *b=(int*)buf;
        while((int)p<(int)buf_end) *b++=*p++;
        cur = buf+((int)cur)%4;
        buf_end = cur+size;
    }
    while(buf_end-cur<MINREAD) {
        // fill buffer
        int c;
        c = read(0, buf_end, buf+BUFSIZE-buf_end);
        if(c==0) { ended=1; return cur; }
        buf_end += c;
    }
    return cur;
}

int main() {
    register unsigned char *p;
    int n, i, j;
    buf_end = buf;
    p = fetch(buf);
    n = atoi(p);
    while(*p++!='\n');
    for(i=0; i<HASH_SIZE; i++) hash_head[i] = -1;
    for(i=0; i<n; i++) {
        p=fetch(p);
        while(*p!='-') {
            register unsigned int a=*p++-'0';
            if(*p==' ') goto parse_end;
            a = a*10+*p++-'0';
            if(*p==' ') goto parse_end;
            a = a*10+*p++-'0';
        parse_end:
            p++;
            hash_list_body[i][a/32] |= 1<<(a%32);
        }
        p += 3;
        hash_insert(i);
    }
    printf("%d\n", hash_size);
    return 0;
}

