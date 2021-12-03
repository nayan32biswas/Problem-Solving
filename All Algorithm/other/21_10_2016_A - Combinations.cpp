#include<iostream>
#include<iomanip>
using namespace std;
long double FACT(int N){
    long double X=1;
    for(int i=1; i<=N; i++)
        X*=i;
    return X;
}
int main()
{
    int N, M;
    long double X;
    while(cin>>N>>M){
        if(N == 0 || M == 0) break;
        X = N-M;
        X = FACT(N)/(FACT(X)*FACT(M));
        cout<<N<<" things taken "<<M<<" at a time is "<<fixed<<setprecision(0)<<X<<" exactly."<<endl;
    }
    return 0;
}
