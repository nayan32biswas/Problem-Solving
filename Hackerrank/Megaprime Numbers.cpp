#include <stdio.h>
#include <time.h>
#include <math.h>
#define LMT 32222222
#define MAX 3000000009

bool pri[LMT], ck;
int prime[10000000], s[18];
long long megaprime[10000000];

inline bool Mega(long long num)
{
    int temp;
    while(num>0){
        temp = num%10;
        if(temp==2 || temp==3 || temp==5 || temp==7){
            num/=10;
        }
        else return false;
    }
    return true;
}

inline bool big_megaprime(long long num)
{
    long long root=sqrt(num)+2;
    for(int i=0; prime[i]<root; i++){
        if(num%prime[i]==0)return false;
    }
    return true;
}

inline long long My_str(long long num)
{
    int  temp, i=0;
    while(num>0){
        temp=(num%10);
        if(temp<=2) temp=2;
        else if(temp==3) temp=3;
        else if(temp<=5) temp=5;
        else if(temp<=7) temp=7;
        else temp=11;
        s[i++]=temp;
        num/=10;
    }num=0;
    for(i=i-1; i>=0; (num=(num*10)+s[i]), i--);
    if(!(num&1)) num++;
    return num;
}

void store(long long k)
{
    int J, temp;
    long long i=LMT+1, num, value;
    for(;i<MAX; i+=2){
        num=i, value=0;
        if(Mega(i)==true){
            if(big_megaprime(i)==true)megaprime[k++]=i;
        }
        else{
            num = My_str(i);
            if(num>i)num-=2;
            i = num;
        }
    }
    //printf("%lld\n", k);
}
void seive()
{
    int i, J, root=sqrt(LMT)+2;
    long long k;
    for(i=3, pri[1]=1; i<root; i+=2)if(!pri[i]){
            for(J=i*i; J<LMT; J+=(i<<1)) pri[J]=1;
    }
    prime[0]=2, megaprime[0]=2;
    for(i=3, J=1, k=1; i<LMT; i+=2)if(!pri[i]){
        prime[J++]=i;
        if(Mega(i)==true) megaprime[k++]=i;
    }
    store(k);
}

int Binary_Search(long long key)
{
    int start=0, End=296841, mid;
    End = 67879;
    while(start<=End){
		mid = (start+End)>>1;
		if(megaprime[mid] == key)break;
		else if(megaprime[mid]<key) start = mid+1;
		else if(megaprime[mid]>key) End = mid-1;
	}
	return mid;
}

int main()
{
    seive();
    long long i, J, first, last;
    //printf("%d\n", clock());
    while(scanf("%lld%lld", &first, &last)==2){
        i=Binary_Search(first);
        if(megaprime[i]<first) i++;
        J=Binary_Search(last);
        if(megaprime[J]<last) J++;
        printf("%lld\n", J-i);
    }
    return 0;
}
