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

    int ansv;
    ArrayList<Integer> ans;

    Main(String[] ss, int[] is) {
        this.ss = ss;
        this.is = is;
    }

    void solve() {
        ans = new ArrayList<Integer>();
        for(int i=0; i<ss.length; i++) {
            int v = calc(i);
            if(ansv < v) {
                ansv = v;
                ans.clear();
            }
            if(ansv == v) ans.add(i);
        }
    }

    int calc(int df) {
        final int n = ss.length;
        int[][] min = new int[n][n];
        int[][] max = new int[n][n];
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
            min[i][j] = 40000;
            max[i][j] = -40000;
        }
        for(int i=0; i<n; i++) {
            min[i][i] = max[i][i] = is[(i+df)%n];
        }
        for(int w=1; w<n; w++) {
            for(int i=0; i+w<n; i++) {
                int j = i+w;
                for(int k=i+1; k<=j; k++) {
                    int a, b;
                    if("t".equals(ss[(df+k)%n])) {
                        a = min[i][k-1] + min[k][j];
                        b = max[i][k-1] + max[k][j];
                    }
                    else {
                        a = Math.min(Math.min(min[i][k-1]*min[k][j],
                                              min[i][k-1]*max[k][j]),
                                     Math.min(max[i][k-1]*min[k][j],
                                              max[i][k-1]*max[k][j]));
                        b = Math.max(Math.max(min[i][k-1]*min[k][j],
                                              min[i][k-1]*max[k][j]),
                                     Math.max(max[i][k-1]*min[k][j],
                                              max[i][k-1]*max[k][j]));
                    }
                    min[i][j] = Math.min(min[i][j], a);
                    max[i][j] = Math.max(max[i][j], b);
                }
            }
        }
        return max[0][n-1];
    }
}
