#include <bits/stdc++.h>
using namespace std;
struct data
{
    string s;
    bool operator <(const data &temp)const
    {
        int len1=s.size();
        int len2=temp.s.size();
        if(len1!=len2) return len1<len2;
        return s<temp.s;
    }
} x[200000];
int main()
{
    int n, i;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x[i].s;
    }
    sort(x, x+n);
    for(i=0; i<n; i++)
    {
        cout<<x[i].s<<endl;
    }
    cout<<endl<<clock()<<endl;
    return 0;
}
