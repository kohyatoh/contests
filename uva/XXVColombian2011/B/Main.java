import java.util.*;
import java.math.*;

public class Main {
    BigInteger[][] C;
    int M, K;
    int[] N;

    public void run() {
        C = new BigInteger[75][75];
        for(int i=0; i<75; i++) for(int j=0; j<75; j++) {
            C[i][j] = BigInteger.ZERO;
        }
        C[0][0] = BigInteger.ONE;
        for(int i=0; i<70; i++) for(int j=0; j<70; j++) {
            C[i+1][j] = C[i+1][j].add(C[i][j]);
            C[i+1][j+1] = C[i+1][j+1].add(C[i][j]);
        }
        Scanner sc = new Scanner(System.in);
        for(;;) {
            M = sc.nextInt();
            K = sc.nextInt();
            if(M==0 && K==0) return ;
            N = new int[K];
            for(int i=0; i<K; i++) N[i] = sc.nextInt();
            System.out.println(solve().toString());
        }
    }

    public BigInteger solve() {
        BigInteger[][] dp = new BigInteger[75][75];
        for(int i=0; i<75; i++) for(int j=0; j<75; j++) {
            dp[i][j] = BigInteger.ZERO;
        }
        dp[0][0] = BigInteger.ONE;
        for(int k=0; k<K; k++) for(int i=0; i<=M; i++) {
            for(int j=0; j<=N[k] && i+j<=M; j++) {
                dp[k+1][i+j] = dp[k+1][i+j].add(dp[k][i].multiply(C[i+j][j]));
            }
        }
        return dp[K][M];
    }

    public static void main(String args[]) {
        new Main().run();
    }
}
