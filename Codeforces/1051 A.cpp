#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int arr[Size];
bool isLow(char c) {
    return c>='a' && c<='z';
}
bool isUpper(char c) {
    return c>='A' && c<='Z';
}
bool isNum(char c) {
    return c>='0' && c<='9';
}
int lo, up, dig;
void solve() {
    string str;
    cin>>str;
    lo = up = dig = 0;
    for(auto it : str) {
        if(isLow(it))
            lo++;
        else if(isUpper(it))
            up++;
        else
            dig++;
    }
    if(up==0 && dig==0) {
        str[0] = 'Z', str[1] = '0';
    } else if(lo==0 && dig==0) {
        str[0] = 'a', str[1] = '0';
    } else if(lo==0 && up==0) {
        str[0] = 'Z', str[1] = 'a';
    }
    if(lo>0 && up>0 && dig==0) {
        if(lo>1) {
            for(int i=0; i<str.size(); i++) {
                if(isLow(str[i])) {
                    str[i] = '0';
                    break;
                }
            }
        } else if(up>1) {
            for(int i=0; i<str.size(); i++) {
                if(isUpper(str[i])) {
                    str[i] = '0';
                    break;
                }
            }
        }
    }
    else if(lo>0 && up==0 && dig>0) {
        if(lo>1) {
            for(int i=0; i<str.size(); i++) {
                if(isLow(str[i])) {
                    str[i] = 'A';
                    break;
                }
            }
        } else if(dig>1) {
            for(int i=0; i<str.size(); i++) {
                if(isNum(str[i])) {
                    str[i] = 'A';
                    break;
                }
            }
        }
    }
    else if(lo==0 && up>0 && dig>0) {
        if(up>1) {
            for(int i=0; i<str.size(); i++) {
                if(isUpper(str[i])) {
                    str[i] = 'a';
                    break;
                }
            }
        } else if(dig>1) {
            for(int i=0; i<str.size(); i++) {
                if(isNum(str[i])) {
                    str[i] = 'a';
                    break;
                }
            }
        }
    }

    cout<<str<<endl;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int T;
    string str;
    cin>>T;
    for(int t=1; t<=T; t++) {
        solve();
    }
}
