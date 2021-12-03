#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    string ch;
    scanf("%d", &n);
    cin>>ch;
    for(int i=0; i<n; i++){
        if(( i==0 && ch[i]!='*' && ch[i]!='g' ) || ( i==n-1 && ch[i]!='*' && ch[i]!='g' ))
            continue;

        else if(( ch[i-1]!='*' && ch[i]!='*' ) || ( ch[i]!='*' && ch[i+1]!='*' ))
            continue;

        else if(ch[i]=='g') ch[i]='*';
    }
    cout<<ch<<endl;

    return 0;
}
/*#include<iostream>
#include<string>
#include<regex>
#include<cstdio>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
	int n;
	cin >> n;
	string s;
	cin >> s;
	regex r ("(ogo)(go)*");
	cout << regex_replace (s, r, "***");
	return 0;
}
*/
