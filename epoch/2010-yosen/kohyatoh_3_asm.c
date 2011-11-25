#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define M (1000000)
#define BUFSIZE (16777216) // 2**24

double fv[M];
char* fp[M];
char buf[BUFSIZE];
const double HALF=0.5;


// check
#ifdef EFB_CHECK
#define MEM_DUMP_HERE "call mem_dump\n\t"
int c_N, c_n;
void mem_dump() {
    int i;
    fprintf(stderr, "mem_dump\n");
    fprintf(stderr, "N=%d, n=%d\n", c_N, c_n);
    for(i=0; i<c_N; i++) {
        fprintf(stderr, "%20.12f at %d\n", fv[i], (int)(fp[i]-buf));
    }
}
#else
#define MEM_DUMP_HERE ""
#endif


// statistics
#ifdef EFB_STAT
#define IF_STAT(a) a
int s_reads, s_nrbyte;
int s_writes, s_nwbyte;
int s_steps, s_lcmps, s_rcmps, s_swaps;

void stat_output() {
    fprintf(stderr, "stats\n");
    fprintf(stderr, "  read   : %d bytes read by %d read().\n",
            s_nrbyte, s_reads);
    fprintf(stderr, "  write  : %d bytes written by %d write().\n",
            s_nwbyte, s_writes);
    fprintf(stderr, "  select : %d steps, %d(%d:%d) compares and %d swaps.\n",
            s_steps, s_lcmps+s_rcmps, s_lcmps, s_rcmps, s_swaps);
}
#else
#define IF_STAT(a) ""
#endif


// benchmark
#ifdef EFB_BENCH
#define BENCH_MARK_HERE "call bench_mark\n\t"
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
    ".Lstack_init:\n\t"
        "pushl   %%ebp\n\t"
        "movl    %%esp, %%ebp\n\t"
        "subl    $80, %%esp\n\t"
        "andl    $-16, %%esp\n\t"
        "movl    %%ebp, 60(%%esp)\n\t" // store ebp
        BENCH_MARK_HERE
    ".Lread:\n\t"
        "movl    $buf, %%edi\n\t"
        "movl    $16777216, %%ebx\n\t"
    ".Lread_loop:\n\t"
        // req eax:-,   ebx:nbyte, ecx:-, edx:-, esi:-, edi:p, ebp:-
        // use eax:ret, ebx:nbyte, ecx:x, edx:x, esi:-, edi:p, ebp:-
        "xorl    %%eax, %%eax\n\t" // set fd
        "movl    %%eax, (%%esp)\n\t" // set fd
        "movl    %%edi, 4(%%esp)\n\t" // set buf
        "movl    %%ebx, 8(%%esp)\n\t" // set nbyte
        IF_STAT("addl $1, s_reads\n\t")
        "call    read\n\t"
        "cmpl    $-1, %%eax\n\t"
        "je      .Lread_loop\n\t"
        IF_STAT("addl %%eax, s_nrbyte\n\t")
        "test    %%eax, %%eax\n\t"
        "jz      .Lread_loop_fin\n\t"
        "subl    %%eax, %%ebx\n\t"
        "addl    %%eax, %%edi\n\t"
        "jmp     .Lread_loop\n\t"
    ".Lread_loop_fin:\n\t"
        BENCH_MARK_HERE
        "movl    $buf, %%edi\n\t"
    ".Lparse_N:\n\t"
        "xorl    %%eax, %%eax\n\t"
        "movzbl  (%%edi), %%ecx\n\t"
    ".Lparse_N_loop:\n\t"
        // req eax:a, ebx:-, ecx:c, edx:-, esi:-, edi:p, ebp:-
        // use eax:a, ebx:-, ecx:c, edx:t, esi:-, edi:p, ebp:-
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "addl    $1, %%edi\n\t"
        "leal    -48(%%ecx,%%edx,2), %%eax\n\t"
        "movzbl  (%%edi), %%ecx\n\t"
        "test    $16, %%ecx\n\t"
        "jnz     .Lparse_N_loop\n\t"
    ".Lparse_N_loop_fin:\n\t"
        "movl    %%eax, 12(%%esp)\n\t" // store N
#ifdef EFB_CHECK
        "movl    %%eax, c_N\n\t" // store c_N
#endif
        "addl    $1, %%edi\n\t"
    ".Lparse_n:\n\t"
        "xorl    %%ebx, %%ebx\n\t"
        "movzbl  (%%edi), %%ecx\n\t"
    ".Lparse_n_loop:\n\t"
        // req eax:N, ebx:a, ecx:c, edx:-, esi:-, edi:p, ebp:-
        // use eax:N, ebx:a, ecx:c, edx:t, esi:-, edi:p, ebp:-
        "leal    (%%ebx,%%ebx,4), %%edx\n\t"
        "addl    $1, %%edi\n\t"
        "leal    -48(%%ecx,%%edx,2), %%ebx\n\t"
        "movzbl  (%%edi), %%ecx\n\t"
        "test    $16, %%ecx\n\t"
        "jnz     .Lparse_n_loop\n\t"
    ".Lparse_n_loop_fin:\n\t"
        "movl    %%ebx, 16(%%esp)\n\t" // store n
#ifdef EFB_CHECK
        "movl    %%ebx, c_n\n\t" // store c_n
#endif
        BENCH_MARK_HERE
        "addl    $1, %%edi\n\t"
    ".Lparse_fractions:\n\t"
        "xorl    %%ebp, %%ebp\n\t"
    ".Lparse_fractions_loop:\n\t"
        // req eax:-, ebx:-, ecx:-, edx:-, esi:-, edi:p, ebp:i
        "movl    %%edi, fp(,%%ebp,4)\n\t" // store fp[i]
    ".Lparse_a:\n\t"
        // use eax:a, ebx:s, ecx:c, edx:t, esi:t, edi:p, ebp:i
        "movzbl  (%%edi), %%eax\n\t"
        "movzbl  1(%%edi), %%edx\n\t"
        "addl    $1, %%edi\n\t"
        "xorl    %%ebx, %%ebx\n\t"
        "test    $16, %%eax\n\t"
        "setz    %%bl\n\t"
        "cmovz   %%edx, %%eax\n\t"
        "addl    %%ebx, %%edi\n\t"
        "subl    $48, %%eax\n\t"
        "movzbl  (%%edi), %%ecx\n\t"
        "subl    $48, %%ecx\n\t"
        "jb      .Lparse_b\n\t"
        "addl    $1, %%edi\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "movzbl  (%%edi), %%esi\n\t"
        "leal    (%%ecx,%%edx,2), %%eax\n\t"
        "subl    $48, %%esi\n\t"
        "jb      .Lparse_b\n\t"
        "addl    $1, %%edi\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "movzbl  (%%edi), %%ecx\n\t"
        "leal    (%%esi,%%edx,2), %%eax\n\t"
        "subl    $48, %%ecx\n\t"
        "jb      .Lparse_b\n\t"
        "addl    $1, %%edi\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "movzbl  (%%edi), %%esi\n\t"
        "leal    (%%ecx,%%edx,2), %%eax\n\t"
        "subl    $48, %%esi\n\t"
        "jb      .Lparse_b\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "addl    $1, %%edi\n\t"
        "leal    (%%esi,%%edx,2), %%eax\n\t"
    ".Lparse_b:\n\t"
        // use eax:c, ebx:t, ecx:a, edx:t, esi:t, edi:p, ebp:i
        "addl    $1, %%edi\n\t"
        "movzbl  (%%edi), %%ecx\n\t"
        "movzbl  1(%%edi), %%esi\n\t"
        "addl    $1, %%edi\n\t"
        "xorl    %%edx, %%edx\n\t"
        "test    $16, %%ecx\n\t"
        "setz    %%dl\n\t"
        "cmovz   %%esi, %%ecx\n\t"
        "addl    %%edx, %%ebx\n\t"
        "addl    %%edx, %%edi\n\t"
        "movl    %%eax, %%esi\n\t"
        "negl    %%eax\n\t"
        "test    $1, %%ebx\n\t"
        "cmovnz  %%eax, %%esi\n\t"
        "movzbl  (%%edi), %%eax\n\t"
        "subl    $48, %%ecx\n\t"
        "cvtsi2sd    %%esi, %%xmm0\n\t"
        "subl    $48, %%eax\n\t"
        "jb      .Lstore_fraction_data\n\t"
        "addl    $1, %%edi\n\t"
        "leal    (%%ecx,%%ecx,4), %%edx\n\t"
        "movzbl  (%%edi), %%esi\n\t"
        "leal    (%%eax,%%edx,2), %%ecx\n\t"
        "subl    $48, %%esi\n\t"
        "jb      .Lstore_fraction_data\n\t"
        "addl    $1, %%edi\n\t"
        "leal    (%%ecx,%%ecx,4), %%edx\n\t"
        "movzbl  (%%edi), %%eax\n\t"
        "leal    (%%esi,%%edx,2), %%ecx\n\t"
        "subl    $48, %%eax\n\t"
        "jb      .Lstore_fraction_data\n\t"
        "addl    $1, %%edi\n\t"
        "leal    (%%ecx,%%ecx,4), %%edx\n\t"
        "movzbl  (%%edi), %%esi\n\t"
        "leal    (%%eax,%%edx,2), %%ecx\n\t"
        "subl    $48, %%esi\n\t"
        "jb      .Lstore_fraction_data\n\t"
        "leal    (%%ecx,%%ecx,4), %%edx\n\t"
        "addl    $1, %%edi\n\t"
        "leal    (%%esi,%%edx,2), %%ecx\n\t"
    ".Lstore_fraction_data:\n\t"
        "cvtsi2sd    %%ecx, %%xmm1\n\t"
        "addl    $1, %%ebp\n\t"
        "divsd    %%xmm1, %%xmm0\n\t"
        "addl    $1, %%edi\n\t"
        "movsd    %%xmm0, fv-8(,%%ebp,8)\n\t"
        "cmpl    12(%%esp), %%ebp\n\t" // N
        "jne     .Lparse_fractions_loop\n\t"
        MEM_DUMP_HERE
        BENCH_MARK_HERE
    ".Lselect:\n\t"
        "movl    12(%%esp), %%edi\n\t"
        "movl    %%edi, %%ebp\n\t"
        "subl    16(%%esp), %%ebp\n\t"
        "xorl    %%esi, %%esi\n\t"
        "subl    $1, %%edi\n\t"
        "movsd   HALF, %%xmm3\n\t"
    ".Lselect_loop:\n\t"
        IF_STAT("addl $1, s_steps\n\t")
        "movsd   fv(,%%esi,8), %%xmm0\n\t"
        "leal    -1(%%esi), %%ebx\n\t"
        "addsd   fv(,%%edi,8), %%xmm0\n\t"
        "leal    1(%%edi), %%edx\n\t"
        "mulsd   %%xmm3, %%xmm0\n\t"
    ".Lpartition_loop:\n\t"
    ".Lleft_loop:\n\t"
        IF_STAT("addl $1, s_lcmps\n\t")
        "movsd   fv+8(,%%ebx,8), %%xmm1\n\t"
        "addl    $1, %%ebx\n\t"
        "ucomisd %%xmm1, %%xmm0\n\t"
        "ja      .Lleft_loop\n\t"
    ".Lright_loop:\n\t"
        IF_STAT("addl $1, s_rcmps\n\t")
        "movsd   fv-8(,%%edx,8), %%xmm2\n\t"
        "subl    $1, %%edx\n\t"
        "ucomisd %%xmm2, %%xmm0\n\t"
        "jb      .Lright_loop\n\t"
        "cmpl    %%ebx, %%edx\n\t"
        "jle     .Ldo_drop\n\t"
    ".Lswap:\n\t"
        IF_STAT("addl $1, s_swaps\n\t")
        "movl    fp(,%%ebx,4), %%eax\n\t"
        "movl    fp(,%%edx,4), %%ecx\n\t"
        "movsd   %%xmm1, fv(,%%edx,8)\n\t"
        "movsd   %%xmm2, fv(,%%ebx,8)\n\t"
        "movl    %%eax, fp(,%%edx,4)\n\t"
        "movl    %%ecx, fp(,%%ebx,4)\n\t"
        "jmp     .Lpartition_loop\n\t"
    ".Ldo_drop:\n\t"
        "subl    $1, %%ebx\n\t"
        "addl    $1, %%edx\n\t"
        "cmpl    %%ebp, %%ebx\n\t"
        "cmovge  %%ebx, %%edi\n\t"
        "cmovl   %%edx, %%esi\n\t"
    ".Lselect_loop_next:\n\t"
        "cmpl    %%esi, %%edi\n\t"
        "jg      .Lselect_loop\n\t"
        MEM_DUMP_HERE
        BENCH_MARK_HERE
    ".Lwrite:\n\t"
        "movl    12(%%esp), %%eax\n\t"
        "subl    16(%%esp), %%eax\n\t"
        "xorl    %%ebx, %%ebx\n\t"
        "movl    fp(,%%eax,4), %%edi\n\t"
    ".Lstrlen_loop:\n\t"
        "movzbl  (%%edi,%%ebx), %%ecx\n\t"
        "addl    $1, %%ebx\n\t"
        "cmpl    $10, %%ecx\n\t"
        "jne     .Lstrlen_loop\n\t"
    ".Lwrite_loop:\n\t"
        "movl    $1, %%eax\n\t"
        "movl    %%eax, (%%esp)\n\t" // set fd
        "movl    %%edi, 4(%%esp)\n\t" // set buf
        "movl    %%ebx, 8(%%esp)\n\t" // set nbyte
        IF_STAT("addl $1, s_writes\n\t")
        "call    write\n\t"
        "cmpl    $-1, %%eax\n\t"
        "je      .Lwrite_loop\n\t"
        IF_STAT("addl %%eax, s_nwbyte\n\t")
        "addl    %%eax, %%edi\n\t"
        "subl    %%eax, %%ebx\n\t"
        "ja      .Lwrite_loop\n\t"
    ".Lclean_stack:\n\t"
        "movl    60(%%esp), %%esp\n\t"
        "popl    %%ebp\n\t"
    : : : "eax", "ebx", "ecx", "edx", "esi", "edi");
#ifdef EFB_STAT
    stat_output();
#endif
#ifdef EFB_BENCH
    bench_output();
#endif
    return 0;
}

