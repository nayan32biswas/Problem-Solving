package some_practic;
import java.util.*;
import java.math.*;
public class Some_practic {
    public static void main(String[] args) {
        Integer();
        Biginteger();
        Bigdecimal();
        string_char();
    }
    public static void Integer(){
        Scanner input = new Scanner(System.in);
            int arr[] = new int[10];
            for(int i=0; i<5; i++)
                arr[i] = input.nextInt();
            Arrays.sort(arr);
            for(int i=0; i<5; i++)
                System.out.println(arr[i]);
        double a,b,pow,sqrt,abs,Max,Min;
        a = input.nextDouble();
        b = input.nextDouble();
        sqrt = Math.sqrt(a);
        pow = Math.pow(a, b);
        abs = Math.abs(a);
        Max = Math.max(a,b);
        Min = Math.min(a,b);
        System.out.println(sqrt+" "+pow+" "+abs+" "+Max+" "+Min);
        return;
    }
    public static void Biginteger(){
        Scanner input = new Scanner(System.in);
        int INT, compare;
        BigInteger big_A = input.nextBigInteger();
        BigInteger big_B = input.nextBigInteger();
        BigInteger SUM, SUB, MULT, DIV, POW, MOD, ABS, AND, ANDNOT;
        BigInteger POW_MOD = BigInteger.valueOf(1000);
        SUM = big_A.add(big_B);
        SUB = big_A.subtract(big_B);
        MULT = big_A.multiply(big_B);
        DIV = big_A.divide(big_B);
        POW = big_A.pow(100);
        /*We canot use BigInteger  pow BigInteger becouse power value is too large*/
        MOD = big_A.mod(big_B);/*this is A Modulas B*/
        POW_MOD = big_B.modPow(big_A,POW_MOD);
        /*Here B is base A is the power and POW_MOD is modulas value*/
        ABS = big_A.abs();
        INT = big_B.intValue();
        AND = big_A.and(big_B);/* This is and oparator*/
        ANDNOT = big_A.andNot(big_B);/* This is andnot oparator*/
        compare = big_A.compareTo(big_B);
        if(compare>0)
            compare=1;/*A in gater than B*/
        else if(compare==0)
            compare=0;/*A equl B*/
        else if(compare<0)
            compare=-1;/*A less than B*/
        System.out.print(SUM+" "+SUB+" "+MULT+" "+DIV+" "+POW+" "+MOD+" "+POW_MOD);
        System.out.println(" "+ABS+" "+INT+" "+AND+" "+ANDNOT);
        return;
    }
    public static void Bigdecimal(){
        Scanner input = new Scanner(System.in);
        BigDecimal BD_A, BD_B, BD_MOD;
        BD_A = input.nextBigDecimal();
        /* Declaration and get input in BigDecimal (This is a float value)*/
        BD_B = input.nextBigDecimal();
        BD_MOD = BD_A.remainder(BD_B);/*Here remainder is a mod function*/
        System.out.println(BD_MOD);
    }
    public static void string_char(){
        Scanner input = new Scanner(System.in);
        String string_array; //For Dicliaring a integer array;
        char ch; //For Dicliaring a integer array;
        ch = input.next().charAt(0);// get input a single charecter;
        System.out.println(ch);
        string_array = input.nextLine();// get input with space;
        string_array = input.next();// get input without space;
        System.out.println(string_array);
        return;
    }
}
