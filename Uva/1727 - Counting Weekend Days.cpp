#include <bits/stdc++.h>
using namespace std;
int MM[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string T[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
string TT[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
map<string, int>week, month;
int main()
{
    int i=0;
    for(auto s : T) week[s] = i++;
    i = 0;
    for(auto s : TT) month[s] = MM[i++];
    int test, M, coun, W;
    string w, m;
    cin>>test;
    while(test--){
        cin>>m>>w;
        M = month[m];
        W = week[w];
        coun = 0;
        while(M--){
            if(W%7==6 || W%7==5) coun++;
            W++;
        }
        cout<<coun<<endl;
    }
    return 0;
}
