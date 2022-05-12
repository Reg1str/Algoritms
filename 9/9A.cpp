#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

enum Colors {
    white, grey, black
};
ofstream fout("topsort.out");

void dfs(vector<vector<int> > &graph, vector<Colors> &passed, int current_edge, vector<int> &answer) {
    passed[current_edge] = grey;
    for (int i = 0; i < graph[current_edge].size(); i++) {
        int cur = graph[current_edge][i];
        if (passed[cur] == white) {
            dfs(graph, passed, cur, answer);
        }
        if (passed[cur] == grey) {
            fout << -1 << endl;
            exit(0);
        }
    }
    passed[current_edge]=black;
    answer.push_back(current_edge + 1);
}

void topologicalSort(vector<vector<int> > &graph, vector<Colors> &passed, vector<int> &answer) {
    for (int i = 0; i < passed.size(); i++) {
        if (passed[i] == white){
            dfs(graph,passed,i,answer);
        }
    }

    reverse(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i ++){
        fout << answer[i] << " ";
    }
}


int main() {
    ifstream fin("topsort.in");

    int n, m;
    fin >> n >> m;

    vector <vector<int>> graph;
    vector <Colors> passed_vertex;

    graph.resize(n);
    passed_vertex.resize(n);

    for (auto &i : passed_vertex) {
        i = white;
    }

    for (int i = 0; i < m; i++) {
        int vertex_x, vertex_y;
        fin >> vertex_x >> vertex_y;
        graph[vertex_x - 1].push_back(vertex_y - 1);
    }

    vector<int> answer;

    topologicalSort(graph, passed_vertex, answer);

    fin.close();

}
