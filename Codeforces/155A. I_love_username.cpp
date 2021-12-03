#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, num, Max, Min, ans=0;
    scanf("%d", &n);
    cin>>num;
    Max=num, Min=num;
    for(int i=1; i<n; i++){
        scanf("%d", &num);
        if(num>Max){
            Max=num;
            ans++;
        }
        else if(num<Min){
            Min=num;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
