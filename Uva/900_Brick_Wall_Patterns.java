import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while(input.hasNext()){
            long in,ans,a=1,b=1,c;
            in = input.nextLong();
            if(in==0)
                break;
            for(int i=0; i<in; i++){
                c = a+b;
                a = b;
                b = c;
            }
            System.out.println(a);
        }
    }
}
