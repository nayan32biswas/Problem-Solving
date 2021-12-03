#include <bits/stdc++.h>
using namespace std;
map<string, bool>pass;
int Max_length, len;
bool check;
string loginAttempt;
vector<string>ans;
void Find(int pos){
    if(pos==len) {
        check = true;
        return;
    }
    string temp="";
    for(int i=pos; i<len; i++){
        if(check) return;
        if(temp.size()>=Max_length) return;
        temp += loginAttempt[i];
        if(pass[temp]==true){
            ans.push_back(temp);
            Find(i+1);
            if(check) return;
            ans.pop_back();
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test, N;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &N);
        check = false;
        Max_length = 0;
        pass.clear();
        string temp;
        ans.clear();
        for(int i=0; i<N; i++){
            cin>>temp;
            pass[temp] = true;
            Max_length = max(Max_length, int(temp.size()));
        }
        cin>>loginAttempt;
        len = loginAttempt.size();
        Find(0);
        if(check){
            len = ans.size();
            for(int i=0; i<len; i++){
                if(i) printf(" ");
                cout<<ans[i];
            }
            puts("");
        }
        else {
            puts("WRONG PASSWORD");
        }
    }
    cout<<clock()<<endl;
    return 0;
}
