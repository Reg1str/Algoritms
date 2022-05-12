#include <fstream>
#include <vector>

using namespace std;

void dfs(int &cur, vector<vector<int>> &graph, vector<bool> &passed, vector<int> &tSorted) {
    passed[cur] = true;
    for (auto i : graph[cur]) {
        if (!passed[i]) {
            dfs(i, graph, passed, tSorted);
        }
    }
    tSorted.push_back(cur);
}

int main() {
    ifstream fin("hamiltonian.in");
    ofstream fout("hamiltonian.out");

    bool result = true;
    int n, m;
    int x, y;
    fin >> n >> m;

    vector <vector<int>> graph(100000);
    vector<bool> passed;
    passed.assign(n, false);
    graph.resize(n);
    vector<int> tSorted;

    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        graph[x - 1].push_back(y - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!passed[i]) {
            dfs(i, graph, passed, tSorted);
        }
    }

    for (auto i = tSorted.size() - 1; i > 0; i--) {
        bool localResult = false;
        for (int j = 0; j < graph[tSorted[i]].size(); j++) {
            if (graph[tSorted[i]][j] == tSorted[i - 1]) {
                localResult = true;
            }
        }
        if (!localResult){
            result = false;
            break;
        }
    }

    if (result) {
        fout << "YES";
    } else {
        fout << "NO";
    }
    return 0;
}