#include <bits/stdc++.h>
using namespace std;
#define Size 100
#define p(n) return cout<<n<<endl, 0
int arr[Size];
bool is(long long n){
    int sum=0;
    while(n && sum<=10){
        sum += n%10;
        n/=10;
    }
    if(sum==10) return true;
    return false;

}
int main()
{
    int k=0, n;
    cin>>n;
    for(int i=15;; i++){
        if(is(i)){
            k++;
            if(k==n) p(i);
        }
    }
    return 0;
}

