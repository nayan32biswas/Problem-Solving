#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int year, ans;
    cin>>year;
    if(year%4==0){
        if(year%100==0 && year%400!=0){
            ans = 13;
        }
        else ans = 12;
    }
    else ans = 13;
    printf("%d.09.%d\n", ans, year);
    return 0;
}
