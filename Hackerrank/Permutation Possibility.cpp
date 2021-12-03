#include <iostream>
using namespace std;
int arr[100009];
int main()
{
    int n, x;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>x;
        if(arr[i]==1){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
