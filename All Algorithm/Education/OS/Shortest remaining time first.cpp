#include <bits/stdc++.h>
using namespace std;

vector<string>processes;
map<string, int>completionT;
map<string, int >arrivalT;
map<string, int >burstT;
map< string, int >turnaroundT;
map< string, int >waitingT;
map< pair<int, int>, string >ganttChart;

void input();

void showAverageTime();
void showGanttChart();
void showChart();

void startExecution();
void generateTime();

int main() {
    freopen("inputrr.txt", "r", stdin);
    input();
    startExecution();
    generateTime();

    showChart();
    showAverageTime();
    showGanttChart();
}


void startExecution() {
    priority_queue< pair<int, string>, vector< pair<int, string> >, greater<pair< int, string >> >Que;
    priority_queue< pair<int, string>, vector< pair<int, string> >, greater<pair< int, string >> >visited;
    map< string, int >remain;
    int burstTfinished = 0;
    for(auto it : processes) {
        remain[it] = burstT[it];
    }
    for(auto it : arrivalT) {
        visited.push(make_pair(it.second, it.first));
    }
    while(!visited.empty() && visited.top().first<=burstTfinished) {
        Que.push(make_pair(remain[visited.top().second], visited.top().second));
        visited.pop();
    }

    while(!Que.empty()) {
        int lo, hi;

        pair<int, string> current = Que.top();
        Que.pop();
        lo = burstTfinished;

        if(!visited.empty()) {
            remain[current.second]--;
            hi = burstTfinished+1;
            burstTfinished = hi;

            /// how many process arrive at this time. all of process pushed into queue.
            while(!visited.empty() && visited.top().first<=burstTfinished) {
                Que.push(make_pair(remain[visited.top().second], visited.top().second));
                visited.pop();
            }
        } else {
            hi = burstTfinished+remain[current.second];
            remain[current.second] = 0;
            burstTfinished = hi;
        }

        ganttChart[make_pair(lo, hi)] = current.second;

        /// if this process doesn't finished yet then push in the queue.
        if(remain[current.second]<=0) {
            completionT[current.second] = hi;
        } else {
            current.first = remain[current.second];
            Que.push(current);
        }
    }
}


void generateTime() {
    for(auto it : processes) {
        turnaroundT[it] = completionT[it]-arrivalT[it];
        waitingT[it] = turnaroundT[it]-burstT[it];
    }
}
void input() {
    string str;
    while(cin>>str) {
        int AT, BT;
        cin>>AT>>BT;
        arrivalT[str] = AT;
        burstT[str] = BT;
        processes.push_back(str);
    }
}
void showAverageTime(){
    int TAT=0, WT = 0;
    for(auto it : processes){
        TAT += turnaroundT[it];
        WT += waitingT[it];
    }
    cout<<"Average Turnaround Time is: "<<(double(TAT)/processes.size())<<endl;
    cout<<"Average Waiting Time is: "<<(double(WT)/processes.size())<<endl;
    cout<<endl;
}
void showChart(){
    int n = 6;
    cout<<"PNO   AT    BT    CT   TAT    WT"<<endl;
    for(auto it : burstT){
        cout<<it.first;
        cout<<setw(n)<<arrivalT[it.first];
        cout<<setw(n)<<burstT[it.first];
        cout<<setw(n)<<completionT[it.first];
        cout<<setw(n)<<turnaroundT[it.first];
        cout<<setw(n)<<waitingT[it.first];
        cout<<endl;
    }
    cout<<endl;
}
void showGanttChart() {
    cout<<"Gantt Chart"<<endl;
    for(auto it : ganttChart) {
        cout<<it.second<<" "<<it.first.first<<" "<<it.first.second<<endl;
    }
    cout<<endl;
}
