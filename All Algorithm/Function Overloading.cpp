#include <iostream>
using namespace std;
int add(int a, int b){
    return a+b;
}
int add(int a, int b, int c){
    return a+b;
}
float add(float a, float b){
    return a+b;
}
double add(double a, double b){
    return a+b;
}
int main()
{
    cout<<add(5,6)<<endl;
    cout<<add(5,6,7)<<endl;
    cout<<add(5.5,6.2)<<endl;
    cout<<add((float)5.3,(float)6.1)<<endl;
    return 0;
}
