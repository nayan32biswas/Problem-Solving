#include <bits/stdc++.h>
using namespace std;
map<string, char>Map;
void bild();
int main()
{
    //freopen("input.txt", "r", stdin);
    bild();
    int test, t=0;
    string str;
    cin>>test;
    cin.ignore();
    while(test--)
    {
        getline(cin, str);
        if(t) puts("");
        printf("Message #%d\n", ++t);
        string s="";
        bool ck=false;
        for(auto it : str)
        {
            if(it==' ')
            {
                if(ck) printf(" "), ck = false;
                else if(s.size()!=0)
                {
                    cout<<Map[s];
                    ck = true;
                }
                s = "";
            }
            else s+=it, ck=false;
        }
        if(s.size()!=0) cout<<Map[s];
        puts("");
    }
    return 0;
}
void bild()
{
    Map[".-"] = 'A',   Map[".---"] = 'J', Map["..."] = 'S',   Map[".----"] = '1', Map[".-.-.-"] = '.',  Map["---..."] = ':';
    Map["-..."] = 'B', Map["-.-"] = 'K',  Map["-"] = 'T',     Map["..---"] = '2', Map["--..--"] = ',',  Map["-.-.-."] = ';';
    Map["-.-."] = 'C', Map[".-.."] = 'L', Map["..-"] = 'U',   Map["...--"] = '3', Map["..--.."] = '?',  Map["-...-"] = '=';
    Map["-.."] = 'D',  Map["--"] = 'M',   Map["...-"] = 'V',  Map["....-"] = '4', Map[".----."] = '\'', Map[".-.-."] = '+';
    Map["."] = 'E',    Map["-."] = 'N',   Map[".--"] = 'W',   Map["....."] = '5', Map["-.-.--"] = '!',  Map["-....-"] = '-';
    Map["..-."] = 'F', Map["---"] = 'O',  Map["-..-"] = 'X',  Map["-...."] = '6', Map["-..-."] = '/',   Map["..--.-"] = '_';
    Map["--."] = 'G',  Map[".--."] = 'P', Map["-.--"] = 'Y',  Map["--..."] = '7', Map["-.--."] = '(',    Map[".-..-."] = '"';
    Map["...."] = 'H', Map["--.-"] = 'Q', Map["--.."] = 'Z',  Map["---.."] = '8', Map["-.--.-"] = ')',  Map[".--.-."] = '@';
    Map[".."] = 'I',   Map[".-."] = 'R',  Map["-----"] = '0', Map["----."] = '9', Map[".-..."] = '&';

    //for(auto it : Map) cout<<setw(6)<<it.first<<setw(3)<<it.second<<endl;

}
