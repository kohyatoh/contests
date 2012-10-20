import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        BigInteger b = BigInteger.ONE;
        for (int i = 1; i <= n+1; i++) {
            b = b.multiply(BigInteger.valueOf(i));
        }
        System.out.println(b.add(BigInteger.valueOf(2)).toString());
        for (int i = 0; i < n; i++) {
            System.out.println(i+2);
        }
    }
}
