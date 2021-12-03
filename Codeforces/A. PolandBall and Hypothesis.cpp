#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num, i=0, x, root, J;
    cin>>num;
    if(num==1){
        cout<<"3"<<endl;
        return 0;
    }
    while(true){
        x=(num*i)+1;
        if(x%2==0){
            cout<<i<<endl;
            return 0;
        }
        else if(x&1){
            root = sqrt(x);
            for(J=2; J<=root; J++){
                if(x%J==0){
                    cout<<i<<endl;
                    return 0;
                }
            }
        }
        i++;
    }
}
