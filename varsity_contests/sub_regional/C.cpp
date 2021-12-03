#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    string A, ans="", key;
    cin>>n;
    cin.ignore();
    getline(cin, A);
    cin>>m;
    bool CapsLock=false;
    for(int i=0; i<m; i++){
        cin>>key;
        if(key=="CapsLock"){
            CapsLock = !CapsLock;
        }
        else if (key=="Backspace"){
            if(ans.size()>0)
                ans.pop_back();
        }
        else if(key=="Space"){
            ans += " ";
        }
        else{
            if(CapsLock==true){
                key[0]-=32;
                //cout<<"\t"<<key[0]<<endl;
                ans += key[0];
            }
            else{
                ans += key;
            }
        }
        //cout<<key<<endl;
    }
    //cout<<"\n"<<ans<<endl;
    puts(ans==A ? "Correct" :"Incorrect");

    return 0;
}

