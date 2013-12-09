import java.io.*;
import java.math.*;
import java.util.*;

public class C {
    static int T;
    static int n;
    static String a;
    static BigInteger[] scs;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for (int _ = 0; _ < T; _++) {
            n = sc.nextInt();
            a = sc.next();
            scs = new BigInteger[n];
            for (int i = 0; i < n; i++) {
                scs[i] = BigInteger.ZERO;
            }
            int ix = 0, cur = 0;
            while (ix < a.length()) {
                ix = turn(cur, ix);
                cur = (cur + 1) % n;
            }
//            System.out.println(n + ": " + a);
//            for (int i = 0; i < n; i++) System.out.println(scs[i]);
            Arrays.sort(scs);
            System.out.println(scs[n-1]);
        }
    }

    public static int turn(int p, int ix) {
        char c = a.charAt(ix);
        if ('0' <= c && c <= '9') {
            scs[p] = scs[p].add(BigInteger.valueOf((int)(c - '0')));
        }
        else {
            char op = c;
            while (!('0' <= c && c <= '9')) {
                ix++;
                if (ix == a.length()) return ix;
                c = a.charAt(ix);
            }
            if (op == 'X') scs[p] = scs[p].multiply(BigInteger.valueOf((int)(c - '0')));
            if (op == 'D') scs[p] = scs[p].divide(BigInteger.valueOf((int)(c - '0')));
            if (op == 'S') scs[p] = scs[p].subtract(BigInteger.valueOf((int)(c - '0')));
        }
        return ix + 1;
    }
}
