#include <stdio.h>

#define N (100000)
#define HASHSIZE (131072)
#define BUFSIZE (65536)

char buf[BUFSIZE] __attribute__((aligned(32)));
int head[HASHSIZE];
int bits[N][32] __attribute__((aligned(128)));
unsigned mask[4] __attribute__((aligned(16))) = { 0xffffffffu, 0xffffffffu, 0xffffffffu, 127, };

#ifdef EFB_CHECK
int c_n;

void input_dump() {
    int i, j;
    fprintf(stderr, "input\n");
    for(i=0; i<c_n; i++) {
        for(j=0; j<31; j++) {
            fprintf(stderr, "%x,", bits[i][j]);
        }
        fprintf(stderr, "%x,\n", bits[i][31]&127);
    }
}

void link_dump() {
    int i;
    fprintf(stderr, "head\n");
    for(i=0; i<HASHSIZE; i++) {
         int p=head[i];
         if(p) fprintf(stderr, "%d\n", (p-((int)bits))/128);
         else fprintf(stderr, "-1\n");
    }
    fprintf(stderr, "next\n");
    for(i=0; i<c_n; i++) {
         unsigned p=bits[i][31]&(-128);
         if(p) fprintf(stderr, "%d\n", (p-((int)bits))/128);
         else fprintf(stderr, "-1\n");
    }
}
#endif


// statistics
#ifdef EFB_STAT
#define IF_STAT(a) a
int s_reads, s_nrbyte;
int s_writes, s_nwbyte;

void stat_output() {
    fprintf(stderr, "stats\n");
    fprintf(stderr, "  read   : %d bytes read by %d read().\n",
            s_nrbyte, s_reads);
    fprintf(stderr, "  write  : %d bytes written by %d write().\n",
            s_nwbyte, s_writes);
}
#else
#define IF_STAT(a) ""
#endif


// benchmark
#ifdef EFB_BENCH
#define BENCH_MARK_HERE "call bench_mark\n\t"
#include <sys/time.h>
int markc, markv[10];

void bench_mark() {
    static struct timeval tv;
    gettimeofday(&tv, NULL);
    markv[markc++] = tv.tv_usec;
}

void bench_output() {
    int i;
    fprintf(stderr, "bentch: ");
    for(i=0; i<markc-1; i++) {
        if(i>0) fprintf(stderr, ", ");
        fprintf(stderr, "%d", markv[i+1]-markv[i]);
    }
    fprintf(stderr, "\n");
}
#else
#define BENCH_MARK_HERE ""
#endif


int main() {
    __asm__(
        "pushl   %%ebp\n\t"
        "movl    %%esp, %%ebp\n\t"
        "subl    $80, %%esp\n\t"
        "andl    $-16, %%esp\n\t"
        "movl    %%ebp, 60(%%esp)\n\t"
        BENCH_MARK_HERE
    ".Lread_first:\n\t"
        "movl    $buf, %%esi\n\t"
        "movl    $65536, %%ebx\n\t"
    ".Lread_first_loop:\n\t"
        // req eax:-, ebx:nbyte, ecx:-, edx:-, esi:p, edi:-, ebp:-
        // use eax:x, ebx:nbyte, ecx:x, edx:x, esi:p, edi:-, ebp:-
        "xorl    %%eax, %%eax\n\t"
        "movl    %%eax, (%%esp)\n\t" // set fd
        "movl    %%esi, 4(%%esp)\n\t" // set buf
        "movl    %%ebx, 8(%%esp)\n\t" // set nbyte
        IF_STAT("addl $1, s_reads\n\t")
        "call    read\n\t"
        "cmpl    $-1, %%eax\n\t"
        "je      .Lread_first_loop\n\t" // retry on error
        "test    %%eax, %%eax\n\t"
        "jz      .Lread_first_end\n\t"
        IF_STAT("addl %%eax, s_nrbyte\n\t")
        "addl    %%eax, %%esi\n\t"
        "subl    %%eax, %%ebx\n\t"
        "ja      .Lread_first_loop\n\t"
    ".Lread_first_end:\n\t"
    ".Latoi:\n\t"
        "movl    $buf, %%esi\n\t"
        "movzbl  buf, %%ecx\n\t"
        "xorl    %%ebp, %%ebp\n\t"
        "subl    $48, %%ecx\n\t"
    ".Latoi_loop:\n\t"
        // req eax:-, ebx:-, ecx:d, edx:-, esi:p, edi:-, ebp:a
        // use eax:-, ebx:-, ecx:d, edx:t, esi:p, edi:-, ebp:a
        "leal    (%%ebp,%%ebp,4), %%edx\n\t"
        "addl    $1, %%esi\n\t"
        "leal    (%%ecx,%%edx,2), %%ebp\n\t"
        "movzbl  (%%esi), %%ecx\n\t"
        "subl    $48, %%ecx\n\t"
        "jae     .Latoi_loop\n\t"
    ".Latoi_end:\n\t"
        "addl    $1, %%esi\n\t"
        "movl    %%ebp, 24(%%esp)\n\t" // store n
#ifdef EFB_CHECK
        "movl    %%ebp, c_n\n\t" // store c_n
#endif
    ".Lparse_arrays:\n\t"
        "movl    $bits-128, %%edi\n\t"
    ".Lparse_arrays_loop:\n\t"
        // req eax:d, ebx:-, ecx:c, edx:-, esi:p, edi:q, ebp:n
        // use eax:a, ebx:c, ecx:c, edx:t, esi:p, edi:q, ebp:i
    ".Lparse_arrays_loop_increment:\n\t"
        "movzbl  (%%esi), %%eax\n\t"
        "movzbl  1(%%esi), %%ecx\n\t"
        "addl    $128, %%edi\n\t"
        "subl    $48, %%eax\n\t"
        "subl    $1, %%ebp\n\t"
        "jb      .Lcreate_hashset\n\t"
    ".Lparse:\n\t"
        "addl    $1, %%esi\n\t"
        "subl    $48, %%ecx\n\t"
        "jb      .Lstore_bit\n\t"
        "addl    $1, %%esi\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "movzbl  (%%esi), %%ebx\n\t"
        "leal    (%%ecx,%%edx,2), %%eax\n\t"
        "subl    $48, %%ebx\n\t"
        "jb      .Lstore_bit\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "addl    $1, %%esi\n\t"
        "leal    (%%ebx,%%edx,2), %%eax\n\t"
    ".Lstore_bit:\n\t"
        "subl    $1, %%eax\n\t"
        "addl    $1, %%esi\n\t"
        "movl    %%eax, %%ecx\n\t"
        "movl    $1, %%edx\n\t"
        "shrl    $3, %%eax\n\t"
        "andl    $7, %%ecx\n\t"
        "shll    %%cl, %%edx\n\t"
        "orb     %%dl, (%%edi,%%eax)\n\t"
        "movzbl  (%%esi), %%eax\n\t"
        "movzbl  1(%%esi), %%ecx\n\t"
        "subl    $48, %%eax\n\t"
        "jae     .Lparse\n\t"
    ".Ltest_buf:\n\t"
        "addl    $3, %%esi\n\t"
        "cmpl    $buf+65536-1024, %%esi\n\t" // BUFSIZE-1024
        "jb      .Lparse_arrays_loop\n\t"
    ".Lread:\n\t"
        // req eax:-, ebx:-, ecx:-, edx:-, esi:p, edi:q, ebp:i
        // use eax:-, ebx:c, ecx:c, edx:t, esi:p, edi:q, ebp:i
        "movl    %%esi, %%ebx\n\t"
        "subl    $65536-1024, %%esi\n\t" // BUFSIZE-1024
        "andl    $-32, %%ebx\n\t"
        "movl    %%esi, 12(%%esp)\n\t" // store p
        "leal    1024-65536(%%ebx), %%esi\n\t" // 1024-BUFSIZE
    ".Lmemcpy_loop:\n\t"
        "movdqa  (%%ebx), %%xmm0\n\t"
        "movdqa  16(%%ebx), %%xmm1\n\t"
        "addl    $32, %%ebx\n\t"
        "movdqa  %%xmm0, (%%esi)\n\t"
        "movdqa  %%xmm1, 16(%%esi)\n\t"
        "addl    $32, %%esi\n\t"
        "cmpl    $buf+65536, %%ebx\n\t" // BUFSIZE
        "jne     .Lmemcpy_loop\n\t"
        "movl    $buf+1024, %%esi\n\t"
        "movl    $65536-1024, %%ebx\n\t" // BUFSIZE-1024
    ".Lread_loop:\n\t"
        // req eax:-, ebx:nbyte, ecx:-, edx:-, esi:p, edi:-, ebp:-
        // use eax:x, ebx:nbyte, ecx:x, edx:x, esi:p, edi:t, ebp:-
        "xorl    %%eax, %%eax\n\t"
        "movl    %%eax, (%%esp)\n\t" // set fd
        "movl    %%esi, 4(%%esp)\n\t" // set buf
        "movl    %%ebx, 8(%%esp)\n\t" // set nbyte
        IF_STAT("addl $1, s_reads\n\t")
        "call    read\n\t"
        "cmpl    $-1, %%eax\n\t"
        "je      .Lread_loop\n\t" // retry on error
        "test    %%eax, %%eax\n\t"
        "jz      .Lread_end\n\t"
        IF_STAT("addl %%eax, s_nrbyte\n\t")
        "addl    %%eax, %%esi\n\t"
        "subl    %%eax, %%ebx\n\t"
        "ja      .Lread_loop\n\t"
    ".Lread_end:\n\t"
        "movl    12(%%esp), %%esi\n\t" // load p
        "jmp     .Lparse_arrays_loop\n\t"
    ".Lcreate_hashset:\n\t"
        BENCH_MARK_HERE
        "movdqa  mask, %%xmm3\n\t"
        "movl    $bits, %%esi\n\t"
        "movl    24(%%esp), %%ebp\n\t"
        "xorl    %%ebx, %%ebx\n\t"
    ".Lcreate_hashset_loop:\n\t"
        // req eax:-, ebx:hashsize, ecx:-, edx:-, esi:q, edi:-, ebp:i
    ".Lcalc_hash:\n\t"
        "movdqa  (%%esi), %%xmm0\n\t"
        "movdqa  16(%%esi), %%xmm1\n\t"
        "paddd   32(%%esi), %%xmm0\n\t"
        "paddd   48(%%esi), %%xmm1\n\t"
        "paddd   64(%%esi), %%xmm0\n\t"
        "paddd   80(%%esi), %%xmm1\n\t"
        "paddd   96(%%esi), %%xmm0\n\t"
        "paddd   112(%%esi), %%xmm1\n\t"
        "paddd   %%xmm1, %%xmm0\n\t"
        "pshufd  $0x4e, %%xmm0, %%xmm1\n\t"
        "paddd   %%xmm1, %%xmm0\n\t"
        "pshufd  $0xb1, %%xmm0, %%xmm1\n\t"
        "paddd   %%xmm1, %%xmm0\n\t"
        "movd    %%xmm0, %%eax\n\t"
        "andl    $131071, %%eax\n\t"
    ".Lhash_list_iterate:\n\t"
        "leal    head(,%%eax,4), %%edx\n\t"
        "movl    (%%edx), %%edi\n\t"
        "test    %%edi, %%edi\n\t"
        "jz      .Lhash_insert\n\t"
    ".Lhash_test_loop:\n\t"
        // req eax:-, ebx:hashsize, ecx:-, edx:pp, esi:q, edi:p, ebp:i
        "movdqa  (%%edi), %%xmm0\n\t"
        "movdqa  16(%%edi), %%xmm1\n\t"
        "pcmpeqd (%%esi), %%xmm0\n\t"
        "pcmpeqd 16(%%esi), %%xmm1\n\t"
        "pmovmskb    %%xmm0, %%eax\n\t"
        "pmovmskb    %%xmm1, %%ecx\n\t"
        "cmpl    $65535, %%eax\n\t"
        "jne     .Lhash_test_next\n\t"
        "cmpl    $65535, %%ecx\n\t"
        "jne     .Lhash_test_next\n\t"
        "movdqa  32(%%edi), %%xmm0\n\t"
        "movdqa  48(%%edi), %%xmm1\n\t"
        "pcmpeqd 32(%%esi), %%xmm0\n\t"
        "pcmpeqd 48(%%esi), %%xmm1\n\t"
        "pmovmskb    %%xmm0, %%eax\n\t"
        "pmovmskb    %%xmm1, %%ecx\n\t"
        "cmpl    $65535, %%eax\n\t"
        "jne     .Lhash_test_next\n\t"
        "cmpl    $65535, %%ecx\n\t"
        "jne     .Lhash_test_next\n\t"
        "movdqa  64(%%edi), %%xmm0\n\t"
        "movdqa  80(%%edi), %%xmm1\n\t"
        "pcmpeqd 64(%%esi), %%xmm0\n\t"
        "pcmpeqd 80(%%esi), %%xmm1\n\t"
        "pmovmskb    %%xmm0, %%eax\n\t"
        "pmovmskb    %%xmm1, %%ecx\n\t"
        "cmpl    $65535, %%eax\n\t"
        "jne     .Lhash_test_next\n\t"
        "cmpl    $65535, %%ecx\n\t"
        "jne     .Lhash_test_next\n\t"
        "movdqa  96(%%edi), %%xmm0\n\t"
        "movdqa  112(%%edi), %%xmm1\n\t"
        "pand    %%xmm3, %%xmm1\n\t"
        "pcmpeqd 96(%%esi), %%xmm0\n\t"
        "pcmpeqd 112(%%esi), %%xmm1\n\t"
        "pmovmskb    %%xmm0, %%eax\n\t"
        "pmovmskb    %%xmm1, %%ecx\n\t"
        "cmpl    $65535, %%eax\n\t"
        "jne     .Lhash_test_next\n\t"
        "cmpl    $65535, %%ecx\n\t"
        "je      .Lcreate_hashset_loop_increment\n\t"
    ".Lhash_test_next:\n\t"
        "leal    124(%%edi), %%edx\n\t"
        "movl    124(%%edi), %%edi\n\t"
        "xorl    %%ecx, %%ecx\n\t"
        "andl    $-128, %%edi\n\t"
        "jnz     .Lhash_test_loop\n\t"
    ".Lhash_insert:\n\t"
        "orl     %%esi, (%%edx)\n\t"
        "addl    $1, %%ebx\n\t"
    ".Lcreate_hashset_loop_increment:\n\t"
        "addl    $128, %%esi\n\t"
        "subl    $1, %%ebp\n\t"
        "ja      .Lcreate_hashset_loop\n\t"
        BENCH_MARK_HERE
        "movl    %%ebx, %%ecx\n\t"
    ".Lprint:\n\t"
        // req eax:-, ebx:-, ecx:hashsize, edx:-, esi:-, edi:-, ebp:-
        "xorl    %%ebx, %%ebx\n\t"
        "movl    $10, buf+16\n\t"
        "movl    $buf+16, %%edi\n\t"
        "movl    $-858993459, %%esi\n\t"
        "addl    $1, %%ebx\n\t"
    ".Ltostring_loop:\n\t"
        // req eax:-, ebx:l, ecx:a, edx:-,    esi:3435973837, edi:p, ebp:-
        // use eax:t, ebx:l, ecx:a, edx:a/10, esi:3435973837, edi:p, ebp:-
        "movl    %%ecx, %%eax\n\t"
        "mull    %%esi\n\t"
        "shrl    $3, %%edx\n\t"
        "leal    (%%edx,%%edx,4), %%eax\n\t"
        "addl    %%eax, %%eax\n\t"
        "subl    $1, %%edi\n\t"
        "subl    %%eax, %%ecx\n\t"
        "addl    $1, %%ebx\n\t"
        "addl    $48, %%ecx\n\t"
        "movb    %%cl, (%%edi)\n\t"
        "movl    %%edx, %%ecx\n\t"
        "test    %%ecx, %%ecx\n\t"
        "jnz     .Ltostring_loop\n\t"
    ".Lwrite_loop:\n\t"
        // req eax:-, ebx:nbyte, ecx:-, edx:-, esi:-, edi:p, ebp:-
        "movl    $1, %%eax\n\t"
        "movl    %%eax, (%%esp)\n\t"
        "movl    %%edi, 4(%%esp)\n\t"
        "movl    %%ebx, 8(%%esp)\n\t"
        IF_STAT("addl $1, s_writes\n\t")
        "call    write\n\t"
        "cmpl    $-1, %%eax\n\t"
        "je      .Lwrite_loop\n\t" // retry on error
        IF_STAT("addl %%eax, s_nwbyte\n\t")
        "addl    %%eax, %%edi\n\t"
        "subl    %%eax, %%ebx\n\t"
        "ja      .Lwrite_loop\n\t"
        BENCH_MARK_HERE
    ".Lclear_stack:\n\t"
        "movl    60(%%esp), %%esp\n\t"
        "popl    %%ebp\n\t"
    : : : "eax", "ebx", "ecx", "edx", "esi", "edi", "cc");
#ifdef EFB_CHECK
    input_dump();
    link_dump();
#endif
#ifdef EFB_STAT
    stat_output();
#endif
#ifdef EFB_BENCH
    bench_output();
#endif
    return 0;
}

