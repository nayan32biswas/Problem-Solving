#include <bits/stdc++.h>
#define LMT 2000009
using namespace std;
long long arr[LMT];
long long one[LMT], one1, i1, two[LMT], two2, i2, three[LMT], three3, i3;
map<long long, bool>M;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a, b, i, m, c;
    bool ck;
    cin>>n;
    for(i=0; i<n; i++){
            scanf("%lld", &arr[i]);
            M[arr[i]]=1;
    }
    for(i=0; i<n; i++) {
        scanf("%d", &a);
        if(a==1) one[i1++] = arr[i];
        else if(a==2) two[i2++] = arr[i];
        else three[i3++] = arr[i];
    }
    for(i=0; i<n; i++) {
        scanf("%d", &a);
        if(a==1) one[i1++] = arr[i];
        else if(a==2) two[i2++] = arr[i];
        else three[i3++] = arr[i];
    }
    sort(one, one+i1);
    sort(two, two+i2);
    sort(three, three+i3);

    cin>>m;
    for(i=0; i<m; i++){
        scanf("%d", &c);
        ck = false;
        if(c==1){
            for(; one1<i1; one1++){
                if(M[one[one1]]) {

                    printf("%lld", one[one1]);ck = true;
                    M[one[one1]] = 0;
                    break;
                }
            }
        }
        if(c==2){
            for(; two2<i2; two2++){
                if(M[two[two2]]) {
                    printf("%lld", two[two2]);ck = true;
                    M[two[two2]] = 0;
                    break;
                }
            }
        }
        if(c==3){
            for(; three3<i3; three3++){
                if(M[three[three3]]) {
                    printf("%lld", three[three3]);ck = true;
                    M[three[three3]]= 0;
                    break;
                }
            }
        }
        if(!ck) printf("-1");
        printf(" ");
    }
    puts("");
    return 0;
}
