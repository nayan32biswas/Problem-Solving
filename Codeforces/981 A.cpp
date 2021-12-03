#include <bits/stdc++.h>
using namespace std;
bool isPalin(string str)
{
    for(int i=0, j=str.size()-1; i<j; i++, j--)
    {
        if(str[i]!=str[j])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str;
    cin>>str;
    if(str.size()<2)
    {
        return puts("0"), 0;
    }
    int arr[130];
    memset(arr, 0, sizeof(arr));
    int coun = 0;
    for(auto it : str)
    {
        arr[it]++;
        if(arr[it]==1) coun++;
        if(coun>1) break;
    }
    if(coun==1)
    {
        return puts("0"), 0;
    }
    if(isPalin(str)==false)
    {
        cout<<str.size()<<endl;
    }
    else
    {
        cout<<str.size()-1<<endl;
    }
    return 0;
}
