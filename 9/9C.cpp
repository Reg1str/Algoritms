#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void bfs(int &cur, vector<vector<int>> &graph, vector<int> &passed, bool &result) {
    queue<int> queue;
    passed[cur] = 1;
    queue.push(cur);
    while (!queue.empty()) {
        int temp = queue.front();
        queue.pop();
        for (auto i: graph[temp]) {
            if (passed[i] == 0) {
                queue.push(i);
                passed[i] = -1*(passed[temp]);
            } else if (passed[temp] == passed[i])
                result = false;
        }
    }
}


int main() {
    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");

    int n, m;
    int x, y;
    fin >> n >> m;

    vector <vector<int>> graph(n);
    vector<int> passed;

    passed.assign(n, 0);

    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }

    bool answer;
    for (int i = 0; i < n; i++) {
        if (passed[i] == 0) {
            bfs(i, graph, passed,answer);
        }
    }

    if (answer) {
        fout << "YES";
    } else {
        fout << "NO";
    }


    return 0;
}