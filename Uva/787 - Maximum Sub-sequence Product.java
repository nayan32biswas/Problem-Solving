package uva;

import java.util.*;
import java.io.*;
import java.math.*;
public class Seven_Eight_Seven {
	static BigInteger Max;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int End = -999999, i, lo, Size;
		int arr[] = new int[101];
		while(input.hasNext()){
			Max = BigInteger.valueOf(End);
			for(i=0; ; i++){
				arr[i] = input.nextInt();
				if(arr[i]==End) break;
				Max = Max.max(BigInteger.valueOf(arr[i]));
			}
			Size = i;
			for(i=0, lo=0; i<Size; i++){
				if(arr[i]==0){
					Find(arr, lo, i);
					lo = i+1;
				}
			}
			Find(arr, lo, Size);
			System.out.println(Max);
		}
	}
	public static void Find(int arr[], int lo, int hi){
		if(hi-lo==0 || hi-lo==1) {
			Max = Max.max(BigInteger.valueOf(arr[lo]));
			return;
		}
		BigInteger mult = BigInteger.ONE;
		int i, neg = 0;
		for(i=lo; i<hi; i++){
			if(arr[i]<0) neg++;
			mult = mult.multiply(BigInteger.valueOf(arr[i]));
		}
		Max = Max.max(mult);
		if(neg%2==0)
			return;
		
		boolean ck = false;
		for(i=lo, mult = BigInteger.ONE; i<hi; i++){
			if(ck) mult = mult.multiply(BigInteger.valueOf(arr[i]));
			if(arr[i]<0) ck = true;
		}
		ck = false;
		Max = Max.max(mult);
		for(i=hi-1, mult = BigInteger.ONE; i>=lo; i--){
			if(ck) mult = mult.multiply(BigInteger.valueOf(arr[i]));
			if(arr[i]<0) ck = true;
		}
		Max = Max.max(mult);
	}

}
