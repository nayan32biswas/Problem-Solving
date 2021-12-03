#include <bits/stdc++.h>
using namespace std;
struct node
{
    string process= "";
    int time;
    operator <(const node &T) const
    {
        return time>T.time;
    }
};
int main()
{
    freopen("input.txt", "r", stdin);
    int N, pTime, total=0, time=0;
    queue<node>Queue;
    cin>>N;
    string str, P = "p";
    for(int i=0; i<N; i++)
    {
        cin>>pTime;
        node temp;
        temp.process = (P+char(48+i));
        temp.time = pTime;
        Queue.push(temp);
    }
    while(!Queue.empty())
    {
        cout<<"Process "<<Queue.front().process<<" Waiting time is "<<time<<endl;
        if(Queue.size()>1)
        {
            time += Queue.front().time;
            total += time;
        }
        Queue.pop();
    }
    cout<<"Waiting time is "<<total<<endl;
    cout<<"Average waiting time is "<<((double)total)/N<<endl;
    return 0;
}
