#include <bits/stdc++.h>
using namespace std;
class intersecPOINT {
private:
    int xx1, xx2, xx3, xx4, yy1, yy2, yy3, yy4;
public:
    void Input(){
        scanf("%d %d %d %d", &xx1, &yy1, &xx2, &yy2);
        scanf("%d %d %d %d", &xx3, &yy3, &xx4, &yy4);
    }
    void Check() {
        int aaa, bbb, eee, ccc, ddd, fff;
        aaa=-(yy1-yy2);
        bbb=xx1-xx2;
        eee=xx1*yy2-xx2*yy1;
        ccc=-(yy3-yy4);
        ddd=xx3-xx4;
        fff=xx3*yy4-xx4*yy3;

        double detA=aaa*ddd-bbb*ccc;

        if (detA!=0) {
            double x,y;
            x=(eee*ddd-bbb*fff)/detA;
            y=(aaa*fff-eee*ccc)/detA;
            cout<<"POINT "<<fixed<<setprecision(2)<<x<<" "<<fixed<<setprecision(2)<<y<<endl;
        } else if (aaa*xx3+bbb*yy3-eee==0)
            printf("LINE\n");
        else
            printf("NONE\n");
    }
};

main() {
    //freopen("input.txt", "r", stdin);
    int test;
    intersecPOINT in;
    scanf("%d",&test);
    puts("INTERSECTING LINES OUTPUT");
    while (test--) {
        in.Input();
        in.Check();
    }
    puts("END OF OUTPUT");
    return 0;
}

