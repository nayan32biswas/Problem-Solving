#include <bits/stdc++.h>
using namespace std;
struct date
{
    int day, month, year;
};
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nextLeapYear(int year)
{
    return ((year / 4) + 1) * 4;
}
bool leapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
        return true;
    return false;
}
bool underLYDay(date x)
{
    if (leapYear(x.year) && x.month < 3)
        return true;
    return false;
}
bool overLYDay(date x)
{
    if (leapYear(x.year) && x.month > 2)
        return true;
    return false;
}
int sameYear(date one, date two)
{
    if (one.month == two.month)
    {
        return abs(two.day - one.day) + 1;
    }
    int day = month[one.month] - one.day;
    if (underLYDay(one) && overLYDay(two))
        day++;
    one.month++;
    day += two.day;
    for (; one.month < two.month; one.month++)
    {
        day += month[one.month];
    }
    return day + 1;
}

int notSameYear(date one, date two)
{
    date demo;
    demo.day = 30, demo.month = 12, demo.year = one.year;
    int afterOne = sameYear(one, demo) + 1;
    demo.day = 1, demo.month = 1, demo.year = two.year;
    int beforeTwo = sameYear(demo, two);
    int leap = 0;
    for (int nextL = nextLeapYear(one.year); nextL < two.year; nextL += 4)
        if (leapYear(nextL))
        {
            leap++;
            cout << nextL << endl;
        }
    // cout<<afterOne<<" "<<beforeTwo<<" "<<leap<<" "<<(two.year-one.year)*4<<endl;
    return afterOne + beforeTwo + leap + (two.year - one.year - 1) * 365;
}
int main()
{
    freopen("input.txt", "r", stdin);
    date one, two;
    cin >> one.day >> one.month >> one.year;
    cin >> two.day >> two.month >> two.year;
    if (one.year == two.year)
    {
        cout << sameYear(one, two) << endl;
    }
    else
    {
        cout << notSameYear(one, two) << endl;
    }
    return 0;
}