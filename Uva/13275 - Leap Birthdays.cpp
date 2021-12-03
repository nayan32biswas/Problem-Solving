#include <bits/stdc++.h>
using namespace std;
bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else if(year % 4 == 0) return true;
    else return false;
}
int main() {
    int ans, test, day, month, year, year1;
    cin>>test;
    for(int t=1; t<=test; t++){
        cin>>day>>month>>year>>year1;
        ans = 0;
        printf("Case %d: ", t);
        if(day==29 && month==2){
            for(int i=year+4; i<=year1; i+=4) if(isLeapYear(i)) ans++;
        }
        else for(int i=year+1; i<=year1; i++) ans++;
        cout<<ans<<endl;
    }
    return 0;
}

