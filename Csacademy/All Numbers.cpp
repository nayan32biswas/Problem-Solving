#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<int>arr(N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int ccc = clock(), coun = 0;
    do{
        if(arr[0]!=0)for(auto it : arr){}
    }while(next_permutation(arr.begin(), arr.end()));
    cout<<clock()-ccc<<endl;
    cout<<coun<<endl;
}
