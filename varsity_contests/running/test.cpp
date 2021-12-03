#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int>temp;
    for(int i=0; i<10; i++)temp.insert(i);
    for(auto it : temp){
        cout<<it<<" "<<temp.size()<<" ";
        temp.erase(it);
        cout<<temp.size()<<endl;;
    }
}