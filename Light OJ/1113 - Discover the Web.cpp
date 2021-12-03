#include <bits/stdc++.h>
using namespace std;
stack<string>first, second;
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, i;
    cin>>test;
    for(int t=1; t<=test; t++){
        string s, now="http://www.lightoj.com/";
        printf("Case %d:\n", t);
        while(!second.empty()) second.pop();
        while(!first.empty()) first.pop();
        while(cin>>s && s!="QUIT"){
            string web;
            if(s=="VISIT"){
                cin>>web;
                first.push(now);
                while(!second.empty()) second.pop();
                cout<<web<<endl;
                now = web;
            }
            else if(s == "BACK"){
                if(first.empty()){
                    cout<<"Ignored"<<endl;
                    continue;
                }
                second.push(now);
                now = first.top(); first.pop();
                cout<<now<<endl;
            }
            else if(s == "FORWARD"){
                if(second.empty()){
                    cout<<"Ignored"<<endl;
                    continue;
                }
                first.push(now);
                now = second.top(); second.pop();
                cout<<now<<endl;
            }
        }
    }
    return 0;
}
