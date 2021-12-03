#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
class intersecPOINT {
private:
    int xx1, xx2, xx3, xx4, yy1, yy2, yy3, yy4;
public:
    bool Find(pii start1, pii End1, pii start2, pii End2) {
        xx1 = start1.first, yy1 = start1.second;
        xx2 = End1.first, yy2 = End1.second;

        xx3 = start2.first, yy3 = start2.second;
        xx4 = End2.first, yy4 = End2.second;
        return check();
    }
    bool under(int xx1, int xx2, double point) {
        if(xx1>xx2)
            swap(xx1, xx2);
        //cout<<xx1<<" "<<xx2<<" "<<point<<endl;
        return point>=xx1 && point<=xx2;
    }
    bool check() {
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
            //cout<<x<<" "<<y<<endl;
            return under(xx1, xx2, x) && under(xx3, xx4, x) && under(yy1, yy2, y) && under(yy3, yy4, y);/// if true thats mean two line intersection one other
        } else if (aaa*xx3+bbb*yy3-eee==0)
            //puts("Same Line");
            return under(xx1, xx2, xx3) && under(yy1, yy2, yy3) && under(xx3, xx4, xx1) && under(yy3, yy4, yy1); /// if true thats mean two line cross one other
        else
            return false; //puts("No intersection");
    }
    bool solve() {

        pii start, End;
        pii leftTop, rightTop, rightButtom, leftButton;
        cin>>start.first>>start.second>>End.first>>End.second;
        cin>>leftTop.first>>leftTop.second>>rightButtom.first>>rightButtom.second;
        //scanf("%lld%lld%lld%lld", &start.first, &start.second, &End.first, &End.second);
        //scanf("%lld%lld%lld%lld", &leftTop.first, &leftTop.second, &rightButtom.first, &rightButtom.second);
        rightTop = make_pair(rightButtom.first, leftTop.second);
        leftButton = make_pair(leftTop.first, rightButtom.second);
        if(Find(start, End, leftTop, rightTop))
            return true;
        if(Find(start, End, rightTop, rightButtom))
            return true;
        if(Find(start, End, rightButtom, leftButton))
            return true;
        if(Find(start, End, leftButton, leftTop))
            return true;
        if(under(leftTop.first, rightButtom.first, start.first) && under(leftTop.second, rightButtom.second, start.second))
            return true;
        return false;
    }
};


main() {
    freopen("input.txt", "r", stdin);
    int test;
    intersecPOINT inn;
    scanf("%d",&test);
    while (test--) {
        puts(inn.solve() ? "T" : "F");
    }
    return 0;
}

