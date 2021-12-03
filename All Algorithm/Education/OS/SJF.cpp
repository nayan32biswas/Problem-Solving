#include <bits/stdc++.h>
using namespace std;
struct node
{
    string process= "";
    int time;
    bool operator <(const node &T) const
    {
        return time>T.time;
    }
};
string makeStr(int n){
    string str;
    while(n>0){
        str += (n%10)+'0';
        n/=10;
    }
    if(str.size()==0) str = '0';
    sort(str.begin(), str.end());
    return "P"+str;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int N, pTime, total=0, time=0;
    priority_queue<node>Queue;
    cin>>N;
    string str, P = "p";
    for(int i=0; i<N; i++)
    {
        cin>>pTime;
        node temp;
        temp.process = makeStr(i);
        temp.time = pTime;
        Queue.push(temp);
    }
    while(!Queue.empty())
    {
        cout<<"Process "<<Queue.top().process<<" Waiting time is "<<time<<endl;
        if(Queue.size()>1)
        {
            time += Queue.top().time;
            total += time;
        }
        Queue.pop();
    }
    cout<<"Waiting time is "<<total<<endl;
    cout<<"Average waiting time is "<<((double)total)/N<<endl;
    return 0;
}
