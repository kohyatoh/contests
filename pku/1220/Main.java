import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(System.in));
            int T = Integer.valueOf(in.readLine());
            while(T-->0) {
                String[] ws = in.readLine().split(" ");
                BigInteger from = new BigInteger(ws[0]);
                BigInteger to = new BigInteger(ws[1]);
                BigInteger b = BigInteger.ZERO;
                for(int i=0; i<ws[2].length(); i++) {
                    b = b.multiply(from).add(BigInteger.valueOf(c2i(ws[2].charAt(i))));
                }
                StringBuilder s = new StringBuilder();
                do {
                    BigInteger[] bs = b.divideAndRemainder(to);
                    s.append(i2c(bs[1].intValue()));
                    b = bs[0];
                } while(!BigInteger.ZERO.equals(b));
                System.out.print(from.intValue());
                System.out.print(' ');
                System.out.print(ws[2]);
                System.out.println();
                System.out.print(to.intValue());
                System.out.print(' ');
                System.out.print(s.reverse());
                System.out.println();
                System.out.println();
            }
        }
        catch(IOException e) {
            System.err.println(e);
        }
    }

    static char i2c(int i) {
        if(i<10) return (char)('0'+i);
        if(i<36) return (char)('A'+i-10);
        return (char)('a'+i-36);
    }

    static int c2i(char c) {
        if('0'<=c && c<='9') return c-'0';
        if('A'<=c && c<='Z') return c-'A'+10;
        if('a'<=c && c<='z') return c-'a'+36;
        return -1;
    }
}
