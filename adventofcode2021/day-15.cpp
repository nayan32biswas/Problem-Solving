#include <bits/stdc++.h>
using namespace std;

// class Dijkstra

int Size, inc;
vector<vector<pair<int, int>>> graph;
vector<int> parents;
vector<long long> distances;
vector<bool> mark;
int ROW = 0, COL = 0;
vector<vector<int>> node;
int R[] = {-1, 0, 1, 0};
int C[] = {0, 1, 0, -1};

void store_node(int row, int col)
{
    node.resize(row);
    for (int i = 0, pos = 0; i < row; i++)
    {
        node[i].resize(col);
        for (int j = 0; j < col; j++)
            node[i][j] = pos++;
    }
}

void add(int from, int to, int weight)
{
    graph[from].push_back(make_pair(weight, to));
}
void run(int source)
{
    pair<long long, int> current;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;

    fill(mark.begin(), mark.end(), false);
    fill(distances.begin(), distances.end(), INT_MAX);

    distances[source] = 0;
    Q.push(make_pair(0, source));
    while (!Q.empty())
    {
        current = Q.top();
        Q.pop();
        if (mark[current.second] == false)
        {
            for (auto now : graph[current.second])
            {
                now.first += current.first;
                if (distances[now.second] > now.first)
                {
                    distances[now.second] = now.first;
                    Q.push(now);
                }
            }
        }
        mark[current.second] = true;
    }
}

void init(int s)
{
    Size = s;
    graph.resize(Size);
    parents.resize(Size);
    distances.resize(Size);
    mark.resize(Size);
}

bool check_position(int i, int j)
{
    return i >= 0 && i < ROW && j >= 0 && j < COL;
}

void extend_input(vector<vector<int>> &input)
{
    ROW = input.size(), COL = input[0].size();
    // incrise ROW
    for (int i = 0, num; i < ROW; i++)
    {
        for (int j = COL; j < COL * 5; j++)
        {
            num = (input[i][j - COL] + 1) % 10;
            if (num == 0)
                num = 1;
            input[i].push_back(num);
        }
    }
    COL = COL * 5;

    for (int i = ROW, num; i < ROW * 5; i++)
    {
        vector<int> temp;
        for (int j = 0; j < COL; j++)
        {
            num = (input[i - ROW][j] + 1) % 10;
            if (num == 0)
                num = 1;
            temp.push_back(num);
        }
        input.push_back(temp);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    string str;
    vector<vector<int>> input;
    while (getline(cin, str) && str[0])
    {
        vector<int> temp;
        for (char it : str)
            temp.push_back({it - '0'});
        input.push_back(temp);
    }
    // Extend input for second part
    extend_input(input);
    ROW = input.size(), COL = input[0].size();

    init(ROW * COL);
    store_node(ROW, COL);
    for (int i = 0, row, col; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                row = i + R[k], col = j + C[k];
                if (check_position(row, col))
                    add(node[row][col], node[i][j], input[row][col]);
            }
        }
    }
    run(node[0][0]);
    cout << distances[node[ROW - 1][COL - 1]] + input[ROW - 1][COL - 1] - input[0][0] << endl;
}