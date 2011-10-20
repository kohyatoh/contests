import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        new Main().run();
    }

    BigInteger[][] C;
    BigInteger[] dp;

    private void run() {
        C = new BigInteger[64][64];
        for(int i=0; i<64; i++) for(int j=0; j<64; j++) {
            C[i][j] = BigInteger.ZERO;
        }
        C[0][0] = BigInteger.ONE;
        for(int i=0; i<63; i++) for(int j=0; j<63; j++) {
            C[i+1][j] = C[i+1][j].add(C[i][j]);
            C[i+1][j+1] = C[i+1][j+1].add(C[i][j]);
        }
        dp = new BigInteger[64];
        dp[0] = dp[1] = BigInteger.ONE;
        for(int k=2; k<64; k++) {
            dp[k] = BigInteger.ZERO;
            for(int i=1; i<k; i++) {
                BigInteger a = C[k-2][i-1].multiply(dp[i])
                    .multiply(BigInteger.valueOf((1L<<i)-1)).multiply(dp[k-i]);
                dp[k] = dp[k].add(a);
            }
        }
        Scanner sc = new Scanner(System.in);
        for(;;) {
            int n = sc.nextInt();
            if(n==0) return;
            System.out.println(dp[n]);
        }
    }
}
