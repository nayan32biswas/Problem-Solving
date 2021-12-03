import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        BigInteger x, f=BigInteger.valueOf(2), g=BigInteger.ONE, tempf, ansf, ansg, sum;
        BigInteger one=BigInteger.ONE, two=BigInteger.valueOf(2), sev =BigInteger.valueOf(7), ther = BigInteger.valueOf(13);
        BigInteger tweelve = BigInteger.valueOf(12), four = BigInteger.valueOf(4), three = BigInteger.valueOf(3);
        int test, t;
        test = input.nextInt();
        for(t=1; t<=test; t++){
            x = input.nextBigInteger();
            sum = f.add(g);
            tempf = (two.multiply((sum).subtract(one)).multiply(sum.subtract(three)).add(tweelve.multiply(f))).subtract(ther);
            g = (sum).multiply(sum.subtract(four)).add(tweelve.multiply(g)).add(sev);
            
            ansf = tempf.mod(BigInteger.valueOf(1000000007));
            ansg = g.mod(BigInteger.valueOf(1000000007));
            
            System.out.println("Case "+t+": "+ansf+" "+ansg);
            f = tempf;
        }
    }
}