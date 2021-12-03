#include <bits/stdc++.h>
using namespace std;
#define Size 100
int arr[Size];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    reverse(arr, arr+n);
    map<int, bool>Map;
    vector<int>vec;
    for(int i=0; i<n; i++){
        if(Map[arr[i]]==false){
            vec.push_back(arr[i]);
        }
        Map[arr[i]]=true;
    }
    reverse(vec.begin(), vec.end());
    bool check=false;
    cout<<vec.size()<<endl;
    for(auto it : vec){
        if(check) printf(" ");
        printf("%d", it);
        check = true;
    }
    puts("");
    return 0;
}
