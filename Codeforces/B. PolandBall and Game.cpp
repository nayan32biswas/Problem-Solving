#include <iostream>
#include <map>
using namespace std;
map<string, bool>M;
string s;
int n, m, i, ans=0;
int main()
{
    cin>>n>>m;
    if(n>m) cout<<"YES"<<endl;
    else if(n<m) cout<<"NO"<<endl;
    else{
        for(i=0; i<(n<<1); i++){
            cin>>s;
            if(!M[s]){
                M[s]=1;
            }
            else ans++;
        }
        cout<<(ans&1 ? "YES" : "NO")<<endl;
    }
    return 0;
}
