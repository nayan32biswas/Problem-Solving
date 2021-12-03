#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long n, k, i, root, x=1, ans[1000000], temp;
int main()
{
    cin>>n>>k;
    if(n==1 && k>1){puts("-1");return 0;}
    if(k==1){puts("1");return 0;}
    root = (int)sqrt(n);
    ans[0]=1;
    for(i=2; i<=root; i++){
        if(n%i==0){
            ans[x]=i;
            x++;
            if(k==x){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    temp = x;
    if(x==1 && k==2){cout<<n<<endl;return 0;}
    if(x==1 || (x*2)<k){puts("-1");return 0;}
    if(root*root == n) temp--;
    for(i=temp; i>=0; i--){
        if(x==k){
            cout<<n/ans[i]<<endl;
            return 0;
        }
        x++;
    }
    puts("-1");
    return 0;
}
