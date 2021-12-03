#include <bits/stdc++.h>
using namespace std;
pair<int, int> Array[10];
int main()
{
    int N, total=0, time=0;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &Array[i].first);
        Array[i].second = i+1;
    }
    sort(Array, Array+N);
    for(int i=0; i<N; i++)
    {
        printf("Process %d Waiting time is %d\n", Array[i].second, time);
        if(i<N-1)
        {
            time += Array[i].first;
            total += time;
        }
    }
    printf("Total waiting time is %d\n", total);
    printf("Average waiting time is ");
    cout<<((double)total)/N<<endl;
    return 0;
}
/*
input data
6
2 5 7 1 10 6
*/
