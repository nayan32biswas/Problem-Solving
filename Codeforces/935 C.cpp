#include <bits/stdc++.h>
using namespace std;
#define fix fixed<<setprecision(7)
double R, x1, y1, x2, y2;
double x, y;
int main()
{
    cin>>R>>x1>>y1>>x2>>y2;
    double ans = sqrt(pow(abs(x2-x1), 2)+pow(abs(y2-y1), 2));
    double half = (ans+R)/2;
    if(ans>=R){
        cout<<fix<<x1<<" "<<fix<<y1<<" "<<fix<<R<<endl;
        return 0;
    }
    if(ans == 0)
        x = x1, y = y1+half;
    else {
        x = (((x1-x2)*half)/ans)+x2;
        y = (((y1-y2)*half)/ans)+y2;

    }
    cout<<fix<<x<<" "<<fix<<y<<" "<<fix<<half<<endl;
    return 0;
}
