import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            int T = sc.nextInt();
            while(T-->0) {
                BigInteger a = parse(sc.next());
                BigInteger b = parse(sc.next());
                System.out.println(a.add(b));
            }
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }

    static BigInteger parse(String s) {
        if(s.charAt(0)=='+') s = s.substring(1);
        return new BigInteger(s);
    }
}
