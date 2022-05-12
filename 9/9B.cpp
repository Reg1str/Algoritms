#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


void dfs(int &cur, vector<vector<int>> &graph, vector<string> &passed, vector<int> &answer, int &start, int &finish) {
    passed[cur] = "GREY";
    for (int i: graph[cur]) {
        if (passed[i] == "GREY") {
            start = i;
            finish = cur;
        } else if (passed[i] == "BLACK") {
            answer[i] = cur;
            dfs(i, graph, passed, answer, start, finish);
        }
    }
    passed[cur] = "BLACK";
}

int main() {
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");

    vector <string> passed;
    vector<int> answer;
    int start = -1, finish = -1;

    int n, m;
    int x, y;
    fin >> n >> m;
    vector <vector<int>> graph(n);

    passed.assign(n, "WHITE");
    answer.assign(n, -1);
    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        graph[x - 1].push_back(y - 1);
    }

    for (int i = 0; i < n; i++)
        if (passed[i] == "WHITE") {
            dfs(i, graph, passed, answer, start, finish);
        }

    if (start == -1) {
        fout << "NO";
    } else {
        fout << "YES" << endl;
        vector<int> reverseAnswer; 
        reverseAnswer.push_back(start + 1);
        for (int i = finish; i != start; i = answer[i])
            reverseAnswer.push_back(i + 1);
        for (int i = reverseAnswer.size() - 1; i >= 0; i--) {
            fout << reverseAnswer[i] << " ";
        }
    }

    return 0;
}