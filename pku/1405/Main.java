import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            final int n = sc.nextInt();
            BigInteger z = BigInteger.ONE;
            for(int i=1; i<=n; i++) {
                BigInteger x = z.add(BigInteger.ONE);
                System.out.println(x);
                z = z.multiply(x);
            }
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }
}
