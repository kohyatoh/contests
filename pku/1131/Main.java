import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            while(sc.hasNext()) System.out.println(solve(sc.nextLine()));
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }

    static String solve(String src) {
        final int n = src.length()-2;
        BigInteger oct = new BigInteger(src.substring(2), 8);
        String dig = oct.multiply(BigInteger.valueOf(5).pow(3*n)).toString();
        StringBuilder res = new StringBuilder("0.");
        for(int i=0; i<3*n-dig.length(); i++) res.append('0');
        res.append(dig);
        int m = res.length();
        while(res.charAt(m-1)=='0') m--;
        return src + " [8] = " + res.substring(0, m) + " [10]";
    }
}
