#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli digit_sum(lli num){
    lli sum=0;
    while(num>0){
        sum += num%10;
        num/=10;
    }
    return sum;
}
lli prime_sum(lli num){
    lli sum = 0;
    for(lli i=2; i*i<=num; i++){
        while(num%i==0){
            num/=i;
            sum+=digit_sum(i);
        }
    }
    if(num>1)sum+=digit_sum(num);
    return sum;
}
int main(){
    lli num;
    cin>>num;
    puts(digit_sum(num)==prime_sum(num) ? "1" : "0");
}