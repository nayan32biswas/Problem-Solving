#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    //freopen("Input.txt", "r", stdin);
    int n, test, arr[60], i=0, J;
    cin>>test;
    for(i=1; i<=test; i++){
        cin>>arr[i];
    }
    for(i=1; i<=test; i++){
        n = i;
        for(J=1; J<=test; J++){
            if(arr[J]==n){
                n = J;
                break;
            }
        }
        for(J=1; J<=test; J++){
            if(arr[J]==n){
                n = J;
                break;
            }
        }
        cout<<n<<endl;
    }
    return 0;
}
