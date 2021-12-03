#include <bits/stdc++.h>
using namespace std;
int h[100000];
void store() {
    int p2=0, p3=0, p5=0, p7=0, temp;
    h[0]=1;
    for(int i=1;i<5842;i++){
        temp = min(2*h[p2],3*h[p3]);
        h[i]=min(temp,min(5*h[p5],7*h[p7]));
        if(h[i]==2*h[p2]) p2++;
        if(h[i]==3*h[p3]) p3++;
        if(h[i]==5*h[p5]) p5++;
        if(h[i]==7*h[p7]) p7++;
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    store();
    int n, x, num;
    while(scanf("%d", &n)==1 && n) {
        printf("The %d", n);
        num = n;
        x = n%100;
        n%=10;
        if(x>10 && x<14) printf("th");
        else if(n==1) printf("st");
        else if(n==2) printf("nd");
        else if(n==3) printf("rd");
        else printf("th");
        printf(" humble number is %d.\n", h[num-1]);
    }
    return 0;
}



/*#include <bits/stdc++.h>
using namespace std;
int dp[6200], n;
void store(int Max){
    int i, J, k, num;
    for(i=1, k=0; i<Max; i++){
        num = i;
        while(!(num&1)) num=num>>1;
        while(num%3==0) num/=3;
        while(num%5==0) num/=5;
        while(num%7==0) num/=7;
        if(num<=1) dp[++k]=i;
    }printf("last number position is %d\n", k);
}
/// Passing time is 2734 for Max=200000000;
int main() {
    freopen("input.txt", "r", stdin);
    store(200000000);
    while(scanf("%d", &n)==1 && n){printf("%d\n", dp[n]);}
    cout<<"Passing time is "<<clock()<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int dp[6200], n;
int prime[]={2, 3, 5, 7};
void store(int Max){
    int i, J, k, num;
    for(i=1, k=0; i<Max; i++){
        num = i;
        while(num%prime[0]==0) num=num/prime[0];
        while(num%prime[1]==0) num/=prime[1];
        while(num%prime[2]==0) num/=prime[2];
        while(num%prime[3]==0) num/=prime[3];
        if(num<=1) dp[++k]=i;
    }printf("last number position is %d\n", k);
}
/// Passing time is 8967 for Max = 200000000
int main()
{
    freopen("input.txt", "r", stdin);
    store(200000000);
    while(scanf("%d", &n)==1 && n){
        printf("%d\n", dp[n]);
    }cout<<"Passing time is "<<clock()<<endl;
    return 0;
}
*/
