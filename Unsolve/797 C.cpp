#include <bits/stdc++.h>
using namespace std;
int arr[130], last[130];
char str[100009];
string u;
stack< char >S;
char check(int pos){
    for(int i=97; i<123; i++){
        if(arr[i]>0){
            if(last[i]<pos) arr[i]=0;
            else return (char)i;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%s", str);
    int len, i, j;
    len = strlen(str);
    for(i=0; i<len; i++) arr[str[i]]++, last[str[i]]=i;
    char c;
    for(i=0; i<len; i++){
        c = str[i];
        if(check(i)==c){
            u+=c;
        }
        else S.push(c);
        arr[c]--;
    }
    cout<<u;
    while(!S.empty()){
        printf("%c", S.top());
        S.pop();
    }
    puts("");
}
