#include <iostream>
#include <string>
using namespace std;
int arr[125];
int main()
{
    string s;
    cin>>s;
    int cou=0, len = s.size();
    for(int i=0; i<len; i++){
        arr[s[i]]++;
        if(arr[s[i]]==1)
            cou++;
    }
    if(cou%2==0)
        cout<<"CHAT WITH HER!"<<endl;
    else
        cout<<"IGNORE HIM!"<<endl;

    return 0;
}
