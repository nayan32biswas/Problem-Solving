#include <bits/stdc++.h>
using namespace std;
map<int, int>MAP;
list<int>vec;
int MAX() {
    map<int, int>::reverse_iterator it;
    for(it = MAP.rbegin(); it!=MAP.rend(); ++it) {
        if(it->second>0) {
            return it->first;
        }
        MAP.erase(it->first);
    }
    return 0;
}
int MIN() {
    map<int, int>::iterator it;
    for(it = MAP.begin(); it!=MAP.end(); ++it) {
        if(it->second>0) {
            return it->first;
        }
        MAP.erase(it->first);
    }
    return 0;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int Q, X, temp;
    string ff, ss;
    scanf("%d", &Q);
    while(Q--) {
        cin>>ff>>ss;
        if(ff=="Insert") {
            scanf("%d", &X);
            MAP[X]++;
            if(ss=="Front") {
                vec.push_front(X);
            } else {
                vec.push_back(X);
            }
        } else if(vec.size()>=0) {
            if(ff=="Erase") {
                if(ss=="Front") {
                    temp = vec.front();
                    MAP[temp]--;
                    if(MAP[temp]==0) {
                        MAP.erase(temp);
                    }
                    vec.pop_front();
                } else {
                    temp = vec.back();
                    MAP[temp]--;
                    if(MAP[temp]==0) {
                        MAP.erase(temp);
                    }
                    vec.pop_back();
                }

            } else if(ff=="Get") {
                if(ss=="Front") {
                    printf("%d\n", vec.front());
                } else if(ss=="Back") {
                    printf("%d\n", vec.back());
                } else if(ss=="Max") {
                    printf("%d\n", MAX());
                } else if(ss=="Min") {
                    printf("%d\n", MIN());
                }
            }
        }
    }
    return 0;
}
