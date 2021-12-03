#include <bits/stdc++.h>
using namespace std;
string str = "hello", temp;
int main() {
    //freopen("input.txt", "r", stdin);
    char ch;
    int n, cursor, operation;

    cin>>n>>str;
    cursor = str.size();

    for(int i=0; i<n; i++) {
        scanf("%d", &operation);
        if(operation==1) {
            cin>>temp;
            int len = str.size();
            if(cursor<0) {
                cursor = 0;
            } else if(cursor>len) {
                cursor = len;
            }
            if(temp == "\\b") {
                if(cursor>0) {
                    str.erase(cursor-1, 1);
                    cursor--;
                }
            } else {
                if(cursor >= len) {
                    str += temp;
                } else if(cursor==0) {
                    str = temp+str;
                } else {
                    str.insert(cursor, temp);
                }
                cursor++;
            }
        } else {
            scanf("%d", &cursor);
        }
        //cout<<str<<" "<<cursor<<endl;
    }
    cout<<str<<endl;
    return 0;
}
