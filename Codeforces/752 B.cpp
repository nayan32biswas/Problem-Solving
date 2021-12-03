#include <bits/stdc++.h>
#define N 23333
char s[N],t[N],swp[N],u[N];
int main() {
	scanf("%s%s",s,t);
	int n=strlen(s),ans=0;
	for (char c='a'; c<='z'; ++c)
		swp[c]=c;
	for (int i=0; i<n; ++i){
		if (!u[s[i]] && !u[t[i]]){
            u[s[i]]=u[t[i]]=1;
            ans+=s[i]!=t[i];
			swp[s[i]]=t[i];
            swp[t[i]]=s[i];
		}
        else if (swp[s[i]]!=t[i] || swp[t[i]]!=s[i]){
            puts("-1");
            return 0;
        }
	}
	printf("%d\n",ans);
	for (char c='a'; c!='z'; ++c)
		if (swp[c]!=c){
			printf("%c %c\n",c,swp[c]);
			swp[swp[c]]=swp[c];
		}
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int g[255];
set<pair<int,int> >se;
int main(){
	string s,t;
	int a,b,n,i,j;
	cin>>s>>t;n= s.size();
	for(i=0;i<s.size();++i){
		a= s[i];b= t[i];
		g[a]=b,g[b]=a;
	}
	vector<pair<char,char> >v;
	for(i=0;i<n;++i){
		a= s[i],b= t[i];
		if(g[a]!=b || g[b]!= a){
			printf("-1\n");return 0;
		}
		if(a!=b){
			if(se.count(make_pair(a,b)) || se.count(make_pair(b,a)))continue;
			se.insert(make_pair(a,b));
			v.push_back(make_pair(a,b));
		}
	}
	cout<<v.size()<<endl;
	for(i=0;i<v.size();++i)
		cout<<v[i].first<<" "<<v[i].second<<endl;
}
*/
