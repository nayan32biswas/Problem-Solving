#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, total=0, time=0;
    int Array[10];
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &Array[i]);
    }
    for(int i=0; i<N; i++)
    {
        printf("Process %d Waiting time is %d\n", i, time);
        if(i<N-1)
        {
            time += Array[i];
            total += time;
        }
    }
    printf("Total waiting time is %d\n", total);
    printf("Average waiting time is ");
    cout<<((double)total)/N<<endl;
    return 0;
}
/**
Input Data
6
2 5 7 1 10 6
*/

