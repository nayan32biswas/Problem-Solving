#include <bits/stdc++.h>
using namespace std;
vector<string>store;
string str;
bool isPalin(int lo, int hi){
    for(; lo<hi; lo++, hi--){
        if(str[lo]!=str[hi]) return false;
    }
    return true;
}
void start(){
    store.clear();
    string temp;
    int len = str.size();
    for(int i=0; i<len; i++){
        temp = "";
        for(int j=i; j<len; j++){
            temp += str[j];
            if(isPalin(i, j)){
                store.push_back(temp);
            }
        }
    }
    sort(store.begin(), store.end());
}
int Find(int pos, char ch){
    int coun = 0;
    for(auto it : store[pos]){
        if(it==ch){
            coun++;
        }
    }

    return coun;
}
void Case(){
    int N, Q, pos;
    char ch;
    scanf("%d%d", &N, &Q);
    cin>>str;
    start();

    //for(auto it : store) cout<<it<<" ";puts("");

    while(Q--){
        scanf("%d %c", &pos, &ch);
        pos--;
        //cout<<pos<<" "<<ch<<"..kajsldfkjlas"<<endl;
        cout<<Find(pos, ch)<<endl;
    }
}
int main()
{
    int test;
    scanf("%d", &test);
    while(test--)Case();
    return 0;
}
