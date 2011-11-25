#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N (5000000)
#define PN (5001216)
#define SPAN (12288)
// assert(PN%SPAN==0)
#define P (445)
#define M (890)
#define RBUFSIZE (65536)
#define WBUFSIZE (65536)
char char_of[PN] __attribute__((aligned(4096)));
char rbuf[RBUFSIZE] __attribute__((aligned(16)));
char wbuf[WBUFSIZE];

int magi[M+2] = {3, 4, 5, 12, 7, 24, 11, 60, 13, 84, 17, 144, 19, 180, 23, 264, 29, 420, 31, 480, 37, 684, 41, 840, 43, 924, 47, 1104, 53, 1404, 59, 1740, 61, 1860, 67, 2244, 71, 2520, 73, 2664, 79, 3120, 83, 3444, 89, 3960, 97, 4704, 101, 5100, 103, 5304, 107, 5724, 109, 5940, 113, 6384, 127, 8064, 131, 8580, 137, 9384, 139, 9660, 149, 11100, 151, 11400, 157, 12324, 163, 13284, 167, 13944, 173, 14964, 179, 16020, 181, 16380, 191, 18240, 193, 18624, 197, 19404, 199, 19800, 211, 22260, 223, 24864, 227, 25764, 229, 26220, 233, 27144, 239, 28560, 241, 29040, 251, 31500, 257, 33024, 263, 34584, 269, 36180, 271, 36720, 277, 38364, 281, 39480, 283, 40044, 293, 42924, 307, 47124, 311, 48360, 313, 48984, 317, 50244, 331, 54780, 337, 56784, 347, 60204, 349, 60900, 353, 62304, 359, 64440, 367, 67344, 373, 69564, 379, 71820, 383, 73344, 389, 75660, 397, 78804, 401, 80400, 409, 83640, 419, 87780, 421, 88620, 431, 92880, 433, 93744, 439, 96360, 443, 98124, 449, 100800, 457, 104424, 461, 106260, 463, 107184, 467, 109044, 479, 114720, 487, 118584, 491, 120540, 499, 124500, 503, 126504, 509, 129540, 521, 135720, 523, 136764, 541, 146340, 547, 149604, 557, 155124, 563, 158484, 569, 161880, 571, 163020, 577, 166464, 587, 172284, 593, 175824, 599, 179400, 601, 180600, 607, 184224, 613, 187884, 617, 190344, 619, 191580, 631, 199080, 641, 205440, 643, 206724, 647, 209304, 653, 213204, 659, 217140, 661, 218460, 673, 226464, 677, 229164, 683, 233244, 691, 238740, 701, 245700, 709, 251340, 719, 258480, 727, 264264, 733, 268644, 739, 273060, 743, 276024, 751, 282000, 757, 286524, 761, 289560, 769, 295680, 773, 298764, 787, 309684, 797, 317604, 809, 327240, 811, 328860, 821, 337020, 823, 338664, 827, 341964, 829, 343620, 839, 351960, 853, 363804, 857, 367224, 859, 368940, 863, 372384, 877, 384564, 881, 388080, 883, 389844, 887, 393384, 907, 411324, 911, 414960, 919, 422280, 929, 431520, 937, 438984, 941, 442740, 947, 448404, 953, 454104, 967, 467544, 971, 471420, 977, 477264, 983, 483144, 991, 491040, 997, 497004, 1009, 509040, 1013, 513084, 1019, 519180, 1021, 521220, 1031, 531480, 1033, 533544, 1039, 539760, 1049, 550200, 1051, 552300, 1061, 562860, 1063, 564984, 1069, 571380, 1087, 590784, 1091, 595140, 1093, 597324, 1097, 601704, 1103, 608304, 1109, 614940, 1117, 623844, 1123, 630564, 1129, 637320, 1151, 662400, 1153, 664704, 1163, 676284, 1171, 685620, 1181, 697380, 1187, 704484, 1193, 711624, 1201, 721200, 1213, 735684, 1217, 740544, 1223, 747864, 1229, 755220, 1231, 757680, 1237, 765084, 1249, 780000, 1259, 792540, 1277, 815364, 1279, 817920, 1283, 823044, 1289, 830760, 1291, 833340, 1297, 841104, 1301, 846300, 1303, 848904, 1307, 854124, 1319, 869880, 1321, 872520, 1327, 880464, 1361, 926160, 1367, 934344, 1373, 942564, 1381, 953580, 1399, 978600, 1409, 992640, 1423, 1012464, 1427, 1018164, 1429, 1021020, 1433, 1026744, 1439, 1035360, 1447, 1046904, 1451, 1052700, 1453, 1055604, 1459, 1064340, 1471, 1081920, 1481, 1096680, 1483, 1099644, 1487, 1105584, 1489, 1108560, 1493, 1114524, 1499, 1123500, 1511, 1141560, 1523, 1159764, 1531, 1171980, 1543, 1190424, 1549, 1199700, 1553, 1205904, 1559, 1215240, 1567, 1227744, 1571, 1234020, 1579, 1246620, 1583, 1252944, 1597, 1275204, 1601, 1281600, 1607, 1291224, 1609, 1294440, 1613, 1300884, 1619, 1310580, 1621, 1313820, 1627, 1323564, 1637, 1339884, 1657, 1372824, 1663, 1382784, 1667, 1389444, 1669, 1392780, 1693, 1433124, 1697, 1439904, 1699, 1443300, 1709, 1460340, 1721, 1480920, 1723, 1484364, 1733, 1501644, 1741, 1515540, 1747, 1526004, 1753, 1536504, 1759, 1547040, 1777, 1578864, 1783, 1589544, 1787, 1596684, 1789, 1600260, 1801, 1621800, 1811, 1639860, 1823, 1661664, 1831, 1676280, 1847, 1705704, 1861, 1731660, 1867, 1742844, 1871, 1750320, 1873, 1754064, 1877, 1761564, 1879, 1765320, 1889, 1784160, 1901, 1806900, 1907, 1818324, 1913, 1829784, 1931, 1864380, 1933, 1868244, 1949, 1899300, 1951, 1903200, 1973, 1946364, 1979, 1958220, 1987, 1974084, 1993, 1986024, 1997, 1994004, 1999, 1998000, 2003, 2006004, 2011, 2022060, 2017, 2034144, 2027, 2054364, 2029, 2058420, 2039, 2078760, 2053, 2107404, 2063, 2127984, 2069, 2140380, 2081, 2165280, 2083, 2169444, 2087, 2177784, 2089, 2181960, 2099, 2202900, 2111, 2228160, 2113, 2232384, 2129, 2266320, 2131, 2270580, 2137, 2283384, 2141, 2291940, 2143, 2296224, 2153, 2317704, 2161, 2334960, 2179, 2374020, 2203, 2426604, 2207, 2435424, 2213, 2448684, 2221, 2466420, 2237, 2502084, 2239, 2506560, 2243, 2515524, 2251, 2533500, 2267, 2569644, 2269, 2574180, 2273, 2583264, 2281, 2601480, 2287, 2615184, 2293, 2628924, 2297, 2638104, 2309, 2665740, 2311, 2670360, 2333, 2721444, 2339, 2735460, 2341, 2740140, 2347, 2754204, 2351, 2763600, 2357, 2777724, 2371, 2810820, 2377, 2825064, 2381, 2834580, 2383, 2839344, 2389, 2853660, 2393, 2863224, 2399, 2877600, 2411, 2906460, 2417, 2920944, 2423, 2935464, 2437, 2969484, 2441, 2979240, 2447, 2993904, 2459, 3023340, 2467, 3043044, 2473, 3057864, 2477, 3067764, 2503, 3132504, 2521, 3177720, 2531, 3202980, 2539, 3223260, 2543, 3233424, 2549, 3248700, 2551, 3253800, 2557, 3269124, 2579, 3325620, 2591, 3356640, 2593, 3361824, 2609, 3403440, 2617, 3424344, 2621, 3434820, 2633, 3466344, 2647, 3503304, 2657, 3529824, 2659, 3535140, 2663, 3545784, 2671, 3567120, 2677, 3583164, 2683, 3599244, 2687, 3609984, 2689, 3615360, 2693, 3626124, 2699, 3642300, 2707, 3663924, 2711, 3674760, 2713, 3680184, 2719, 3696480, 2729, 3723720, 2731, 3729180, 2741, 3756540, 2749, 3778500, 2753, 3789504, 2767, 3828144, 2777, 3855864, 2789, 3889260, 2791, 3894840, 2797, 3911604, 2801, 3922800, 2803, 3928404, 2819, 3973380, 2833, 4012944, 2837, 4024284, 2843, 4041324, 2851, 4064100, 2857, 4081224, 2861, 4092660, 2879, 4144320, 2887, 4167384, 2897, 4196304, 2903, 4213704, 2909, 4231140, 2917, 4254444, 2927, 4283664, 2939, 4318860, 2953, 4360104, 2957, 4371924, 2963, 4389684, 2969, 4407480, 2971, 4413420, 2999, 4497000, 3001, 4503000, 3011, 4533060, 3019, 4557180, 3023, 4569264, 3037, 4611684, 3041, 4623840, 3049, 4648200, 3061, 4684860, 3067, 4703244, 3079, 4740120, 3083, 4752444, 3089, 4770960, 3109, 4832940, 3119, 4864080, 3121, 4870320, 3137, 4920384, 0, 0x7fffffff};

// check
#ifdef EFB_CHECK
int c_num;

void table_dump() {
    int i;
    for(i=0; i<N; i++) {
        fputc(char_of[i], stderr);
    }
    fputc('\n', stderr);
}

void num_dump() {
    fprintf(stderr, "%d\n", c_num);
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
        "movl    $12288, %%edx\n\t" // SPAN
        "movl    $95, %%ebx\n\t"
        "movl    magi, %%ecx\n\t"
        "movl    magi+4, %%eax\n\t"
        "movl    $magi+8, %%edi\n\t"
    ".Lsieve_loop:\n\t"
        // req eax:b, ebx:95, ecx:d, edx:k, esi:-, edi:p, ebp:-
        "movb    %%bl, char_of(%%eax)\n\t"
        "addl    %%ecx, %%eax\n\t"
        "cmpl    %%eax, %%edx\n\t"
        "ja      .Lsieve_loop\n\t"
        "movl    %%eax, -4(%%edi)\n\t"
        "movl    (%%edi), %%ecx\n\t"
        "movl    4(%%edi), %%eax\n\t"
        "addl    $8, %%edi\n\t"
        "cmpl    %%eax, %%edx\n\t"
        "ja      .Lsieve_loop\n\t"
    ".Lsieve_loop_increment:\n\t"
        "movl    magi, %%ecx\n\t"
        "movl    magi+4, %%eax\n\t"
        "movl    $magi+8, %%edi\n\t"
        "addl    $12288, %%edx\n\t" // SPAN
        "cmpl    $5001216+12288, %%edx\n\t" // PN+SPAN
        "jne     .Lsieve_loop\n\t"
        BENCH_MARK_HERE
        "movb    $95, char_of\n\t"
        "movl    $char_of+1, %%ebx\n\t"
        "movl    $98, %%ecx\n\t"
    ".Lnumbering_loop_lower:"
        // req eax:-, ebx:p, ecx:c, edx:-, esi:-, edi:-, ebp:-
        // use eax:t, ebx:p, ecx:c, edx:-, esi:-, edi:-, ebp:-
        "movzbl  (%%ebx), %%eax\n\t"
        "addl    $1, %%ebx\n\t"
        "test    %%eax, %%eax\n\t"
        "jnz     .Lnumbering_loop_lower\n\t"
        "movb    %%cl, -1(%%ebx)\n\t"
        "addl    $1, %%ecx\n\t"
        "cmpl    $123, %%ecx\n\t"
        "jne     .Lnumbering_loop_lower\n\t"
        "movl    $65, %%ecx\n\t"
    ".Lnumbering_loop_upper:\n\t"
        "movzbl  (%%ebx), %%eax\n\t"
        "addl    $1, %%ebx\n\t"
        "test    %%eax, %%eax\n\t"
        "jnz     .Lnumbering_loop_upper\n\t"
        "movb    %%cl, -1(%%ebx)\n\t"
        "addl    $1, %%ecx\n\t"
        "cmpl    $91, %%ecx\n\t"
        "jne     .Lnumbering_loop_upper\n\t"
        "movl    $97, %%ecx\n\t"
        "cmpl    $char_of+5000000, %%ebx\n\t" // N
        "jb      .Lnumbering_loop_lower\n\t"
    ".Lnumbering_loop_end:\n\t"
#ifdef EFB_CHECK
        "call    table_dump\n\t"
#endif
        BENCH_MARK_HERE
    ".Lread_first:\n\t"
        "movl    $rbuf, %%esi\n\t"
        "movl    $65536, %%ebx\n\t" // RBUFSIZE
    ".Lread_first_loop:\n\t"
        // req eax:-, ebx:nbyte, ecx:-, edx:-, esi:p, edi:w, ebp:-
        "xorl    %%eax, %%eax\n\t"
        "movl    %%eax, (%%esp)\n\t" // set fd
        "movl    %%esi, 4(%%esp)\n\t" // set buf
        "movl    %%ebx, 8(%%esp)\n\t" // set nbyte
        IF_STAT("addl $1, s_reads\n\t")
        "call    read\n\t"
        "cmpl    $-1, %%eax\n\t"
        "je      .Lread_first_loop\n\t"
        IF_STAT("addl %%eax, s_nrbyte\n\t")
        "test    %%eax, %%eax\n\t"
        "jz      .Lread_first_loop_end\n\t"
        "addl    %%eax, %%esi\n\t"
        "subl    %%eax, %%ebx\n\t"
        "ja      .Lread_first_loop\n\t"
    ".Lread_first_loop_end:\n\t"
    ".Lparse_init:\n\t"
        "movl    $rbuf, %%esi\n\t"
        "movl    $wbuf, %%edi\n\t"
    ".Lparse:\n\t"
        // req eax:-, ebx:-, ecx:-, edx:-, esi:p, edi:w, ebp:-
        "movzbl  (%%esi), %%eax\n\t"
        "movzbl  1(%%esi), %%ecx\n\t"
        "addl    $1, %%esi\n\t"
        "subl    $48, %%eax\n\t"
        "jb      .Lwrite_newline\n\t"
        "subl    $48, %%ecx\n\t"
        "jb      .Lparse_end\n\t"
        "addl    $1, %%esi\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "movzbl  (%%esi), %%ebx\n\t"
        "leal    (%%ecx,%%edx,2), %%eax\n\t"
        "subl    $48, %%ebx\n\t"
        "jb      .Lparse_end\n\t"
        "addl    $1, %%esi\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "movzbl  (%%esi), %%ecx\n\t"
        "leal    (%%ebx,%%edx,2), %%eax\n\t"
        "subl    $48, %%ecx\n\t"
        "jb      .Lparse_end\n\t"
        "addl    $1, %%esi\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "movzbl  (%%esi), %%ebx\n\t"
        "leal    (%%ecx,%%edx,2), %%eax\n\t"
        "subl    $48, %%ebx\n\t"
        "jb      .Lparse_end\n\t"
        "addl    $1, %%esi\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "movzbl  (%%esi), %%ecx\n\t"
        "leal    (%%ebx,%%edx,2), %%eax\n\t"
        "subl    $48, %%ecx\n\t"
        "jb      .Lparse_end\n\t"
        "addl    $1, %%esi\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "movzbl  (%%esi), %%ebx\n\t"
        "leal    (%%ecx,%%edx,2), %%eax\n\t"
        "subl    $48, %%ebx\n\t"
        "jb      .Lparse_end\n\t"
        "leal    (%%eax,%%eax,4), %%edx\n\t"
        "addl    $1, %%esi\n\t"
        "leal    (%%ebx,%%edx,2), %%eax\n\t"
    ".Lparse_end:\n\t"
        "addl    $1, %%esi\n\t"
#ifdef EFB_CHECK
        "movl    %%eax, c_num\n\t"
        "call    num_dump\n\t"
        "movl    c_num, %%eax\n\t"
#endif
        "test    $1, %%eax\n\t"
        "jz      .Leven\n\t"
        "shrl    $1, %%eax\n\t"
        "movzbl  char_of(%%eax), %%ecx\n\t"
        "movb    %%cl, (%%edi)\n\t"
        "addl    $1, %%edi\n\t"
        "cmpl    $wbuf+65536, %%edi\n\t" // WBUFSIZE
        "je      .Lwrite\n\t"
        "cmpl    $rbuf+65536-16, %%esi\n\t" // RBUFSIZE-16
        "jae     .Lread\n\t"
        "jmp     .Lparse\n\t"
    ".Leven:\n\t"
        "movl    $95, %%edx\n\t"
        "movl    $97, %%ebx\n\t"
        "cmpl    $2, %%eax\n\t"
        "cmovel  %%ebx, %%edx\n\t"
        "movb    %%dl, (%%edi)\n\t"
        "addl    $1, %%edi\n\t"
        "cmpl    $wbuf+65536, %%edi\n\t" // WBUFSIZE
        "je      .Lwrite\n\t"
        "cmpl    $rbuf+65536-16, %%esi\n\t" // RBUFSIZE-16
        "jae     .Lread\n\t"
        "jmp     .Lparse\n\t"
    ".Lwrite:\n\t"
        // w==wbuf+WBUFSIZE
        "movl    $wbuf, %%edi\n\t"
        "movl    $65536, %%ebx\n\t" // WBUFSIZE
    ".Lwrite_loop:\n\t"
        // req eax:-, ebx:nbyte, ecx:-, edx:-, esi:p, edi:w, ebp:-
        "movl    $1, %%eax\n\t"
        "movl    %%eax, (%%esp)\n\t"
        "movl    %%edi, 4(%%esp)\n\t"
        "movl    %%ebx, 8(%%esp)\n\t"
        IF_STAT("addl $1, s_writes\n\t")
        "call    write\n\t"
        "cmpl    $-1, %%eax\n\t"
        "je      .Lwrite_loop\n\t"
        IF_STAT("addl %%eax, s_nwbyte\n\t")
        "addl    %%eax, %%edi\n\t"
        "subl    %%eax, %%ebx\n\t"
        "ja      .Lwrite_loop\n\t"
    ".Lwrite_loop_end:\n\t"
        "movl    $wbuf, %%edi\n\t"
        "cmpl    $rbuf+65536-16, %%esi\n\t" // RBUFSIZE-16
        "jb      .Lparse\n\t"
    ".Lread:\n\t"
        "movdqa  rbuf+65536-16, %%xmm0\n\t" // RBUFSIZE-16
        "subl    $65536-16, %%esi\n\t" // RBUFSIZE-16
        "movdqa  %%xmm0, rbuf\n\t"
        "movl    $rbuf+16, %%ebp\n\t"
        "movl    $65536-16, %%ebx\n\t" // RBUFSIZE-16
    ".Lread_loop:\n\t"
        // req eax:-, ebx:nbyte, ecx:-, edx:-, esi:p, edi:w, ebp:np
        "xorl    %%eax, %%eax\n\t"
        "movl    %%eax, (%%esp)\n\t" // set fd
        "movl    %%ebp, 4(%%esp)\n\t" // sed buf
        "movl    %%ebx, 8(%%esp)\n\t" // set nbyte
        IF_STAT("addl $1, s_reads\n\t")
        "call    read\n\t"
        "cmpl    $-1, %%eax\n\t"
        "je      .Lread_loop\n\t"
        IF_STAT("addl %%eax, s_nrbyte\n\t")
        "test    %%eax, %%eax\n\t"
        "jz      .Lparse\n\t"
        "addl    %%eax, %%ebp\n\t"
        "subl    %%eax, %%ebx\n\t"
        "jbe     .Lparse\n\t"
        "jmp     .Lread_loop\n\t"
    ".Lread_loop_end:\n\t"
    ".Lwrite_newline:\n\t"
        "movl    $10, (%%edi)\n\t"
        "movl    %%edi, %%ebx\n\t"
        "movl    $wbuf, %%edi\n\t"
        "subl    $wbuf-1, %%ebx\n\t"
    ".Lwrite_newline_loop:\n\t"
        // req eax:-, ebx:nbyte, ecx:-, edx:-, esi:-, edi:w, ebp:-
        "movl    $1, %%eax\n\t"
        "movl    %%eax, (%%esp)\n\t"
        "movl    %%edi, 4(%%esp)\n\t"
        "movl    %%ebx, 8(%%esp)\n\t"
        IF_STAT("addl $1, s_writes\n\t")
        "call    write\n\t"
        "cmpl    $-1, %%eax\n\t"
        "je      .Lwrite_newline_loop\n\t"
        IF_STAT("addl %%eax, s_nwbyte\n\t")
        "addl    %%eax, %%edi\n\t"
        "subl    %%eax, %%ebx\n\t"
        "ja      .Lwrite_newline_loop\n\t"
    ".Lwrite_newline_end:\n\t"
        BENCH_MARK_HERE
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


