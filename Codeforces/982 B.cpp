#include <bits/stdc++.h>
using namespace std;
#define Size 200005
#define width first
#define pos second
typedef pair<int, int> ppi;
list<ppi>one, two;
void print(list<ppi> LLL){
    for(auto it : LLL){
        cout<<it.width<<" ";
    }
    puts("");
}
int main(){
    //freopen("input.txt", "r", stdin);
    int n, x;
    ppi temp;
    string str;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &temp.width);
        temp.pos = i+1;
        one.push_back(temp);
    }
    vector<int>ans;
    one.sort();
    cin>>str;
    for(auto it : str){
        if(it=='0'){
            if(one.size()>0){
                temp = one.front();
                one.pop_front();
                two.push_back(temp);

                ans.push_back(temp.pos);
            }
            else{
                temp = two.front();
                two.pop_front();

                ans.push_back(temp.pos);
            }
        }
        else{
            if(two.size()>0){
                temp = two.back();
                two.pop_back();

                ans.push_back(temp.pos);
            }
            else{
                temp = one.back();
                one.pop_back();
                two.push_back(temp);

                ans.push_back(temp.pos);
            }
        }
        //print(one), print(two);
    }
    n*=2;
    for(int i=0; i<n; i++){
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}

