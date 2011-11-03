import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            String[] ss = new String[n];
            int[] is = new int[n];
            for(int i=0; i<n; i++) {
                ss[i] = sc.next();
                is[i] = sc.nextInt();
            }
            Main solver = new Main(ss, is);
            solver.solve();
            System.out.println(solver.ansv);
            boolean first = true;
            for(int ix : solver.ans) {
                if(!first) System.out.print(' ');
                first = false;
                System.out.print(ix+1);
            }
            System.out.println();
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }

    String[] ss;
    int[] is;

    BigInteger ansv;
    ArrayList<Integer> ans;

    Main(String[] ss, int[] is) {
        this.ss = ss;
        this.is = is;
    }

    void solve() {
        ans = new ArrayList<Integer>();
        for(int i=0; i<ss.length; i++) {
            BigInteger bi = calc(i);
            if(ansv==null || ansv.compareTo(bi)<0) {
                ansv = bi;
                ans.clear();
            }
            if(ansv.equals(bi)) ans.add(i);
        }
    }

    BigInteger calc(int df) {
        final int n = ss.length;
        BigInteger[][] min = new BigInteger[n][n];
        BigInteger[][] max = new BigInteger[n][n];
        for(int i=0; i<n; i++) {
            min[i][i] = max[i][i] = BigInteger.valueOf(is[(i+df)%n]);
        }
        ArrayList<BigInteger> ar = new ArrayList<BigInteger>();
        ar.add(null); ar.add(null); ar.add(null); ar.add(null);
        for(int w=1; w<n; w++) {
            for(int i=0; i+w<n; i++) {
                int j = i+w;
                for(int k=i+1; k<=j; k++) {
                    BigInteger a, b;
                    if("t".equals(ss[(df+k)%n])) {
                        a = min[i][k-1].add(min[k][j]);
                        b = max[i][k-1].add(max[k][j]);
                    }
                    else {
                        ar.set(0, min[i][k-1].multiply(min[k][j]));
                        ar.set(1, min[i][k-1].multiply(max[k][j]));
                        ar.set(2, max[i][k-1].multiply(min[k][j]));
                        ar.set(3, max[i][k-1].multiply(max[k][j]));
                        a = Collections.min(ar);
                        b = Collections.max(ar);
                    }
                    if(min[i][j]==null || min[i][j].compareTo(a)>0) {
                        min[i][j] = a;
                    }
                    if(max[i][j]==null || max[i][j].compareTo(b)<0) {
                        max[i][j] = b;
                    }
                }
            }
        }
        return max[0][n-1];
    }
}
