import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger bi = BigInteger.ONE;
        String[] f = new String[400];
        for(int i=1; i<400; i++) {
            bi = bi.multiply(BigInteger.valueOf(i));
            f[i] = bi.toString();
        }
        try {
            int T = sc.nextInt();
            while(T-->0) {
                int n = sc.nextInt();
                int k = sc.nextInt();
                int c = 0;
                for(int i=0; i<f[n].length(); i++) {
                    if(f[n].charAt(i)==k+'0') c++;
                }
                System.out.println(c);
            }
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }
}
