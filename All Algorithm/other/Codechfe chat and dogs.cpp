#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //freopen("Input.txt", "r", stdin);
    int C, D, L, X, Y, test;
    cin>>test;
    while(test--){
        cin>>C>>D>>L;
        if(L%4==0){
            X=D*2;
            if(C>X){
                X = C-X;
                D+=X;
            }
            X = D*4;
            Y = (C+D)*4;
            if(L>=X && L<=Y){
                cout<<"yes"<<endl;
            }
            else cout<<"no"<<endl;
        }
        else cout<<"no"<<endl;
    }
    return 0;
}
