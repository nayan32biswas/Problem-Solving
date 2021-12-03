#include <bits/stdc++.h>
using namespace std;
bool minmumSubsetSum(int arr[], int numberOfElement, int value){
    sort(arr, arr+numberOfElement);
    reverse(arr, arr+numberOfElement); // if remove this line that can be Maximum Subset Sum
    bool table[numberOfElement+1][value+1];
    for(int i=0; i<numberOfElement; i++){
        table[i][0] = true;
    }
    for(int i=1; i<=value; i++){
        table[0][i] = false;
    }
    table[0][arr[0]] = true;
    puts("come");
    for(int i=1; i<numberOfElement; i++){
        for(int j=1; j<=value; j++){
            if(j<arr[i]){
                table[i][j] = table[i-1][j];
            }
            else{
                if(table[i-1][j]==true || table[i-1][j-arr[i]]==true){
                    table[i][j] = true;
                }
                else {
                    table[i][j] = false;
                }
            }
        }
    }

    vector<int>subset;
    for(int i=numberOfElement-1, j=value; i>=0 && j>0; ){
        if(table[i-1][j]==false){
            subset.push_back(arr[i]);
            j = j-arr[i];
            i--;
        }
        else{
            i--;
        }
    }
    for(auto it : subset){
        cout<<it<<" ";
    }
    puts("");
    return table[numberOfElement-1][value];
}
int main()
{
    int arr[] = {2, 3, 1, 7, 8, 10};
    int numberOfElement = (sizeof(arr)/sizeof(arr[0]));
    if(minmumSubsetSum(arr, numberOfElement, 19)){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}
