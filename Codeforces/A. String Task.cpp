#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    string arr;
    while(cin>>arr){
        int ln = arr.length();
        for(int i=0; i<ln; i++){
            if(arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U'||arr[i]=='Y')
                continue;
            else if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||arr[i]=='y')
                continue;
            if(arr[i]>='A'&&arr[i]<='Z')
                arr[i]=arr[i]-'A'+'a';
            cout<<'.'<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}
