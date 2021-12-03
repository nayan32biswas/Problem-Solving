import java.math.*;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int i, len, J, uper;
        boolean ck, ck1, ck2;
        String x;
        char c;
        BigDecimal a, b, sum, one = BigDecimal.valueOf(-1);
        int test = input.nextInt();
        input.nextLine();
        for(int t=0; t<test; t++){
            ck = false; ck1 = false; ck2 = false;
            x = input.nextLine();
            len = x.length();
            
            for(i=0; i<len; i++){
                if(x.charAt(i)=='-') {
                    ck=true;
                }
                if(x.charAt(i)=='1' || x.charAt(i)=='2' || x.charAt(i)=='3' || x.charAt(i)=='4' || x.charAt(i)=='5'){
                    ck2 = true; break;
                }
                else if(x.charAt(i)=='6' || x.charAt(i)=='7' || x.charAt(i)=='8' || x.charAt(i)=='9'){
                    ck2 = true; break;
                }
            }
            if(ck2==false){
                System.out.println("0.0"); continue;
            }
            for(; i<len; i++)if(x.charAt(i)=='-') ck1=true;
            String[] y = x.split(" ");
          
            a = new BigDecimal(y[0]);
            b = new BigDecimal(y[1]);
            if(ck==true) a = a.multiply(one);
            if(ck1==true) b = b.multiply(one);
            uper = a.compareTo(b);
            
            if(ck==false && ck1==false){
                sum = a.add(b);
            }
            else if(ck==true && ck1==false) {
                if(uper==0){
                    System.out.println("0.0"); continue;
                }
                if(uper==1){
                    sum = a.subtract(b);
                    System.out.print("-");
                }
                else{
                    sum = b.subtract(a);
                }
            }
            else if(ck==false && ck1==true) {
                if(uper==0){
                    System.out.println("0.0"); continue;
                }
                if(uper==1){
                    sum = a.subtract(b);
                }
                else{
                    sum = b.subtract(a);
                    System.out.print("-");
                }
            }
            else{
                sum = a.add(b);
                System.out.print("-");
            }
            char[] s = sum.toPlainString().toCharArray();
            len = s.length;
            ck=false;
            for(i=0; i<len; i++) {
                c = s[i];
                if(c=='.'){
                    ck = true;
                    break;
                }
                System.out.print(c);
            }
            
            if(i<len){
                int l;
                for(l = len; l>i; l--){
                    if(s[l-1]!='0')break;
                }
                for(; i<l; i++){
                    System.out.print(s[i]);
                }
                if(s[i-1]=='.'){
                    System.out.println("0");
                }
                else {
                    System.out.println("");
                }
            }
            if(ck==false){
                System.out.println(".0");
            }
        }
    }
}
