#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[4][20];
    cin>>s[0]>>s[1]>>s[2];
    if(strcmp(s[0],"vertebrado")==0){
        if(strcmp(s[1],"ave")==0){
            if(strcmp(s[2],"carnivoro")==0)
                cout<<"aguia"<<endl;
            else cout<<"pomba"<<endl;
        }
        else if(strcmp(s[2],"onivoro")==0)
            cout<<"homem"<<endl;
        else cout<<"vaca"<<endl;
    }
    else{
        if(strcmp(s[1],"inseto")==0){
            if(strcmp(s[2],"hematofago")==0)
                cout<<"pulga"<<endl;
            else cout<<"lagarta"<<endl;
        }
        else if(strcmp(s[2],"hematofago")==0)
            cout<<"sanguessuga"<<endl;
        else cout<<"minhoca"<<endl;
    }
    return 0;
}
