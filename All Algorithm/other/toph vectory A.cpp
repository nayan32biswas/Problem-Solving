#include <bits/stdc++.h>
using namespace std;
string str[] = {
    "",
    "Captain Mohiuddin Jahangir",
    "Sepahi Hamidur Rahman",
    "Sepahi Muhammad Mustafa",
    "Engine Room Artificer Mohammad Ruhul Amin",
    "Flight Lieutenant Matiur Rahman",
    "Lance Naik Munshi Abdur Rouf",
    "Lanc Naik Noor Mohammad Sheikh"
};
int main()
{
    int test, N;
    cin>>test;
    while(test--){
        cin>>N;
        cout<<"Bir Sreshtho "<<str[N]<<": Amra Tomay Vulbo Na."<<endl;
    }
}
