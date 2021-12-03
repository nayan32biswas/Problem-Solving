#include <bits/stdc++.h>
using namespace std;
#define Inf 999999
#define Size 27
int edge, w, x, y, young[Size][Size], middle[Size][Size], node;
int main() {
    //freopen("input.txt", "r", stdin);
    char E, D, A, B;
    while(cin>>edge && edge) {
        for(int i=0; i<Size; i++)
            for(int j=0; j<Size; j++)
                young[i][j]=Inf, middle[i][j] = Inf;
        node = 0;
        for(int i=0; i<edge; i++) {
            cin>>E>>D>>A>>B>>w;
            x = A-65;
            y = B-65;
            if(E=='Y') {
                if(D=='B') {
                    young[x][y] = w;
                    young[y][x] = w;
                } else
                    young[x][y] = w;
            } else {
                if(D=='B') {
                    middle[x][y] = w;
                    middle[y][x] = w;
                } else
                    middle[x][y] = w;
            }
            node = max(node, max(x, y));
        }
        cin>>A>>B;
        x = A-65;
        y = B-65;
        node++;
        for(int k=0; k<node; k++)
            for(int i=0; i<node; i++)
                for(int j=0; j<node; j++)
                    young[i][j] = min(young[i][j], young[i][k]+young[k][j]);
        for(int k=0; k<node; k++)
            for(int i=0; i<node; i++)
                for(int j=0; j<node; j++)
                    middle[i][j] = min(middle[i][j], middle[i][k]+middle[k][j]);

        int ans = Inf;
        set<char>meet;

        if(young[x][y] < middle[y][x]) {
            ans = young[x][y];
            meet.insert(B);
        } else if(young[x][y] > middle[y][x]) {
            ans = middle[y][x];
            meet.insert(A);
        }
        for(int i=0; i<node; i++) {
            if(ans>(young[x][i]+middle[y][i])) {
                ans = young[x][i]+middle[y][i];
                meet.clear();
                meet.insert(i+65);
            } else if(ans==(young[x][i]+middle[y][i])) {
                meet.insert(i+65);
            }
        }
        if(A==B) {
            meet.clear();
            meet.insert(A);
            for(int i=0; i<node; i++)
                for(int j=0; j<node; j++) {
                    if((young[i][j]==0 && middle[i][j]==0))  {
                        meet.insert(j+65);
                    }
                }
            cout<<"0";
            for(auto it : meet)
                cout<<" "<<it;
            puts("");
        } else if(ans!=Inf) {
            cout<<ans;
            for(auto it : meet)
                cout<<" "<<it;
            puts("");
        } else
            puts("You will never meet.");
    }
    return 0;
}
