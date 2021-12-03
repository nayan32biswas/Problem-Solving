#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) {
        for(int J=97; J<k+97 && i<n; J++, i++) {
            printf("%c", J);
        }
        i--;
    }
    puts("");
    return 0;
}
