#include <bits/stdc++.h>
using namespace std;
class Dijkstra {
private:
    int Size, source, MAXI, inc;
    bool RUN;
    vector< vector< pair<int, int> > > graph;
    vector<int> parents;
    vector<long long> distance;
    vector<bool>mark;
public:
    bool hasPath;
    vector<int> findPath(int dis) {
        vector<int>pathArray;
        if(RUN==false || dis==source) {
            return pathArray;
        }
        int past = dis;
        if(parents[past] == source)
            hasPath = true;
        pathArray.push_back(past);
        while(past != source && parents[past] != source) {
            past = parents[past];
            if(past<0)
                break;
            pathArray.push_back(past);

        }
        if(parents[past] == source) {
            hasPath = true;
        }
        pathArray.push_back(source);
        reverse(pathArray.begin(), pathArray.end());
        return pathArray;
    }
    void run(int S) {
        pair<long long, int> current;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> >Q;

        fill(mark.begin(), mark.end(), false);
        fill(distance.begin(), distance.end(), MAXI);
        fill(parents.begin(), parents.end(), -1);

        source = S;
        distance[source] = 0;
        Q.push(make_pair(0, source));
        while(!Q.empty()) {
            current = Q.top();
            Q.pop();
            if(mark[current.second]==false) {
                for(auto now : graph[current.second]) {
                    now.first += current.first;
                    if(distance[now.second]>now.first) {
                        parents[now.second] = current.second;
                        distance[now.second] = now.first;
                        Q.push(now);
                    }
                }
            }
            mark[current.second] = true;
        }
        RUN = true;
        hasPath = false;
    }
    void add(int from, int to, int weight) {
        graph[from].push_back(make_pair(weight, to));
        RUN = false;
    }
    void showTheGroup() {
        int s = 1;
        for(auto it : graph) {
            printf("%d", s++);
            for(auto it1 : it) {
                printf(" -> (%d,%d)", it1.second+1, it1.first+1);
            }
            puts("");
        }
    }
    void Clear() {
        graph.clear();
        parents.clear();
        distance.clear();
        mark.clear();
    }
    void init(int s) {
        RUN = false, Size = s, MAXI = INT_MAX;
        graph.resize(Size);
        parents.resize(Size);
        distance.resize(Size);
        mark.resize(Size);
    }
};

Dijkstra D;
vector<int> extractInteger(string str);
void input(int node);

void solve();
int main() {
    freopen("input.txt", "r", stdin);
    int node;
    while(scanf("%d", &node) != EOF) {
        input(node);
        solve();
    }
    return 0;
}
void solve() {
    vector<int>pathArray;
    int m, start, End;
    scanf("%d", &m);
    puts("-----");
    while(m--) {
        scanf("%d%d", &start, &End);
        D.run(start-1);
        pathArray = D.findPath(End-1);
        if(D.hasPath==false)
            puts("connection impossible");
        else {
            for(int i=0, len=pathArray.size(); i<len; i++) {
                if(i)
                    printf(" ");
                printf("%d", pathArray[i]+1);
            }
            puts("");
        }
    }
}
vector<int> extractInteger(string str) {
    string temp="";
    for(auto it : str) {
        if(isdigit(it)) {
            temp += it;
        } else
            temp += " ";
    }
    str = temp;
    vector<int>number;
    stringstream ss;
    ss << str;
    int found;
    temp = "";
    while (!ss.eof()) {
        ss >> temp;
        if (stringstream(temp) >> found) {
            //cout << found << " ";
            number.push_back(found);
        }
        temp = "";
    }
    return number;
}
void input(int node) {
    string str;
    D.Clear();
    D.init(node);
    vector<int>number;
    for(int i=0; i<node; i++) {
        cin>>str;
        number = extractInteger(str);
        int len = number.size();
        for(int j=1; j<len; j++) {
            D.add(i, number[j]-1, 1);
        }
    }
}
