#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long *factor(int n)
{
    unsigned long long *arr;
    arr = new unsigned long long [n+2];
    arr[0]=1;
    for(int i=1; i<n; i++)
        arr[i]=arr[i-1]*(i+1);

    return arr;
}
int main()
{
    unsigned long long *Factorial;
    int x, n, i;
    while(cin>>n){
        Factorial = factor(n);
        for(i=0; i<n; i++)
            cout<<Factorial[i]<<' ';

        cout<<endl;
        delete(Factorial);
    }
    return 0;
}
