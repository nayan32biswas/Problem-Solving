#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
struct node {
    pair<int, int>left, right;
    bool operator <(const node &T) {
        if(left.first == T.left.first) {
            if(left.second==T.left.second) {
                if(right.first == T.right.first) {
                    return right.second < T.right.second;
                }
                return right.first < T.right.first;
            }
            return left.second<T.left.second;
        }
        return left.first<T.left.first;
    }
};
vector<node> arr;

bool inSide(node aaa, node bbb) {
    if((aaa.right.first >= bbb.left.first) && (aaa.right.second >= bbb.left.second)){
        return true;
    }
    return false;
}
void show() {
    for(auto it : arr) {
        cout<<it.left.first<<" "<<it.left.second;
        cout<<" "<<it.right.first<<" "<<it.right.second<<endl;
    }
    puts("\n");
}
int main() {
    freopen("input.txt", "r", stdin);
    int x, y, x1, y1, n;
    scanf("%d", &n);
    arr.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d%d%d%d", &x, &y, &x1, &y1);
        arr[i].left = make_pair(x, y);
        arr[i].right = make_pair(x1, y1);
    }
    //sort(arr.begin(), arr.end());
    show();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cout<<inSide(arr[i], arr[j])<<" ";
        }
        cout<<endl;
    }
    return 0;
}


//long long Dis(ll x, ll y, ll x1, ll y1) {return sqrt(pow(abs(x-x1), 2) + pow(abs(y-y1), 2));}
