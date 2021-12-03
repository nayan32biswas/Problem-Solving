#include <bits/stdc++.h>
using namespace std;
#define fix fixed<<setprecision(10)
string week[] = {"SUN", "MON", "TUES", "WED", "THUS"};
string Time[] = {"09:00","10:40","12:20","02:00","03:40"};
vector<string> prepair(string &str);
bool is_week(string &str);
bool is_time(string &str);
bool is_Lab(vector<string> &input);
bool has_already(vector<string> &check, string &str);
void temp_print(vector< vector<string> > &input);
void main_print(map<string, map<string, double> > &data);
map<string, map<string, double> > input_processing(vector< vector<string> > &input);
int main()
{
    freopen("input.txt", "r", stdin);
    int TTT = clock();
    string str;
    vector< vector<string> >input;
    vector<string>forcheck;
    while(getline(cin, str))
    {
        if(has_already(forcheck, str))
            continue;
        if(str.size()>0)
            input.push_back(prepair(str));
    }
    forcheck.clear();
    map<string, map<string, double> > data = input_processing(input);
    input.clear();
    main_print(data);
    cout<<clock()-TTT<<endl;
    return 0;
}
void main_print(map<string, map<string, double> > &data)
{
    cout<<setw(6)<<"";
    for(auto it : Time)
        cout<<setw(10)<<it;
    puts("\n");
    for(auto it : week)
    {
        cout<<setw(4)<<it<<": ";
        for(auto it1 : Time)
            cout<<setw(10)<<data[it][it1];
        puts("\n");
    }
}
map<string, map<string, double> > input_processing(vector< vector<string> > &input)
{
    map<string, map<string, double> >data;
    string wk, tm;

    for(auto it : input)
    {
        bool lab = is_Lab(it);
        bool wk_ck, tm_ck, ck;
        wk_ck = tm_ck = ck = false;
        for(auto it1 : it)
        {
            if(is_week(it1))
            {
                wk = it1;
                wk_ck = true;
            }
            else if(is_time(it1))
            {
                tm = it1;
                tm_ck = true;
            }

            if(wk_ck && tm_ck)
            {
                if(lab)
                {
                    if(!ck)
                        data[wk][tm]+=1;
                    else
                        data[wk][tm]+=.3;
                    ck = true;
                }
                else
                    data[wk][tm]+=1;
                wk_ck = tm_ck = false;
            }
        }
    }
    return data;
}
void temp_print(vector< vector<string> > &input)
{
    for(auto it : input)
    {
        for(auto it1 : it)
            cout<<it1<<" ";
        puts("");
    }
    puts("");
}
bool has_already(vector<string> &check, string &str)
{
    string s = "";
    for(auto it : str)
        if(it>='0' && it<='9')
            s+=it;
    for(auto it : check)
        if(it == s)
            return true;
    check.push_back(s);
    return false;
}
vector<string> prepair(string &str)
{
    string s="";
    vector<string>input;
    for(auto it : str)
    {
        if(it>47 && it<123)
            s+=it;
        else if(s!="")
            input.push_back(s),s="";
    }
    return input;
}
bool is_week(string &str)
{
    for(auto it : week)
        if(it==str)
            return true;
    return false;
}
bool is_time(string &str)
{
    for(auto it : Time)
        if(it==str)
            return true;
    return false;
}
bool is_Lab(vector<string> &input)
{
    for(auto it : input)
        if(it=="Lab")
            return true;
    return false;
}
