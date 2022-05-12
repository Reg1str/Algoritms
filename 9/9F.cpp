#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

void winner(int &start, vector<vector<int>> &graph, vector<string> &passed, vector<bool> &result) {
    stack<int> stack;
    stack.push(start);
    while (!stack.empty()) {
        int cur = stack.top();
        if (passed[cur] == "BLACK") {
            stack.pop();
        } else if (passed[cur] == "GREY") {
            bool isWin = false;
            for (auto i: graph[cur]) {
                if (!result[i]) {
                    isWin = true;
                }
            }
            result[cur] = isWin;
            passed[cur] = "BLACK";
            stack.pop();
        } else {
            passed[cur] = "GREY";
            for (auto i: graph[cur]) {
                if (passed[i] == "WHITE") {
                    stack.push(i);
                }
            }
        }
    }
}

int main() {
    ifstream fin("game.in");
    ofstream fout("game.out");

    int n, m, start;
    int x, y;

    fin >> n >> m >> start;
    start--;

    vector <vector<int>> graph(n);
    vector <string> passed;
    vector<bool> result;
    passed.assign(n, "WHITE");
    result.assign(n, false);

    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        graph[x - 1].push_back(y - 1);
    }

    winner(start, graph, passed, result);
    if (result[start]) {
        fout << "First player wins";
    } else {
        fout << "Second player wins";
    }
    return 0;
}
