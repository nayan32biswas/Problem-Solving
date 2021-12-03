#include <bits/stdc++.h>
using namespace std;
int matrix[50][50], value[50], ans[50];
bool arr[10009];
int main()
{
    freopen("input.txt", "r", stdin);
    int r, p, m, n, test, i, J, temp;
    long long sum;
    cin>>test;
    for(int t=1; t<=test; t++) {

        memset(matrix, 0, sizeof(matrix));
        memset(arr, 0, sizeof(arr));

        scanf("%d%d%d%d", &r, &p, &n, &m);
        for(i=0; i<m; i++){
            scanf("%d", &temp);
            arr[temp]=1;
        }

        for(i=0; i<p; i++){
            scanf("%d", &value[i]);
        }
        for(i=0; i<r; i++){
            for(J=0; J<p; J++){
                scanf("%d", &temp);
                if(temp==1 && arr[J]==0){
                    matrix[i][J]=value[J];
                }
            }
        }
        for(i=0; i<r; i++){
            for(J=0, sum=0; J<p; J++){
                sum+=matrix[i][J];
            }
            ans[i]=sum;
        }
        sort(ans, ans+r);
        for(i=0, sum=0; i<n; i++)sum+=ans[i];
        cout<<sum<<endl;
    }
    return 0;
}
