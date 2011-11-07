import java.io.*;
import java.math.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            for(;;) {
                String s = sc.nextLine();
                if("*".equals(s)) return ;
                String a;
                BigInteger b;
                if('0'<=s.charAt(0) && s.charAt(0)<='9') {
                    b = new BigInteger(s);
                    a = btoa(b);
                }
                else {
                    a = s;
                    b = atob(a);
                }
                String r = "";
                BigInteger b1000 = BigInteger.valueOf(1000);
                while(b.compareTo(b1000)>=0) {
                    BigInteger[] m = b.divideAndRemainder(b1000);
                    r = String.format(",%03d%s", m[1].intValue(), r);
                    b = m[0];
                }
                r = b + r;
                System.out.printf("%-22s%s\n", a, r);
            }
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }

    static BigInteger b26 = BigInteger.valueOf(26);

    static BigInteger atob(String a) {
        BigInteger b = BigInteger.ZERO;
        for(int i=0; i<a.length(); i++) {
            b = b.multiply(b26).add(BigInteger.valueOf(a.charAt(i)-'a'+1));
        }
        return b;
    }

    static String btoa(BigInteger b) {
        StringBuilder a = new StringBuilder();
        while(b.compareTo(BigInteger.ZERO)>0) {
            BigInteger[] m = b.subtract(BigInteger.ONE).divideAndRemainder(b26);
            a.append((char)(m[1].intValue()+'a'));
            b = m[0];
        }
        return a.reverse().toString();
    }
}
