import java.util.*;
import java.math.*;
public class ICPC_PRELI_I {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int test = input.nextInt();
        BigInteger k,M,C,res;
        for(int t=1; t<=test; t++){
            int n = input.nextInt();
            BigInteger A=BigInteger.valueOf(1), B=BigInteger.valueOf(2);
            k = input.nextBigInteger();
            M = input.nextBigInteger();
            for(int i=0; i<n; i++){
                C = A.add(B);
                A = B;
                B = C;
            }
            res = k.modPow(A, M);
            System.out.println("Case "+t+": "+res);
        }
    }
    
}
