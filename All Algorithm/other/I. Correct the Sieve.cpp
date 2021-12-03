#include <cstdio>
#include <cmath>
#define N 10000000
bool Prime[N+2];
void sieve() {
	int i, j, root=sqrt(N)+1;
	for(i =3; i <=root; i+=2){
        if(Prime[i]==0){
            for(j=i*i; j<=N; j+=(i+i)){
                Prime[j]=1;
            }
        }
	}
}
int main()
{
	sieve();
	int n, i, num;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&num);
		if((num>1 && num%2==1 && Prime[num]==0) || num==2)
			printf("%d is a prime number.\n",num);
		else printf("%d is not a prime number.\n",num);
	}
	return 0 ;
}
