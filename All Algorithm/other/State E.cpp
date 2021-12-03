#include <bits/stdc++.h>
using namespace std;
int matrix[1111][1111];
int Qsum[1111][1111];
int main()
{
    double ans, sum, cnt;
    int test, a, b, c, d, x, y, i, J;
    scanf("%d%d", &x, &y);
    for(i=1; i<=x; i++){
        for(J=1, sum=0; J<=y; J++){
            scanf("%d", &matrix[i][J]);
            sum+=matrix[i][J];
            Qsum[i][J]=sum;
        }
    }
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        sum=0, cnt=0, ans=0;
        scanf("%d%d%d%d", &a, &b, &c, &c);
        for(i=a; i<=c; i++){
            for(J=b; J<=d; J++){
                sum += matrix[i][J];
                cnt++;
            }
        }
        cout<<sum<<endl;
        for(i=a, sum=0; i<=c; i++){
            sum+=(Qsum[a][d]-Qsum[a][b-1]);
        }
        cout<<sum<<endl;
        sum = sum/cnt;
        for(i=a; i<=c; i++){
            for(J=b; J<=d; J++){
                ans += pow((double)(abs(matrix[i][J]-sum)), 2);
            }
        }
        printf("%.10lf\n", (ans/cnt));
    }
    return 0;
}
