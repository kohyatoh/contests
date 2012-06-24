import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        try {
            int T = Integer.parseInt(r.readLine());
            while (T-- > 0) {
                BigInteger a = new BigInteger(r.readLine());
                BigInteger b = new BigInteger(r.readLine());
                BigInteger c = a.add(b);
                String s = c.toString();
                if (s.length() > 80) s = "overflow";
                System.out.println(s);
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}
