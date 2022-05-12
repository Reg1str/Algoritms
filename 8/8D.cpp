#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dfs(vector<vector<int> > &graph, vector<bool> &passed, int current_edge, int num_of_comp, vector<int> &components) {
    passed[current_edge] = true;
    components[current_edge] = num_of_comp;
    for (int i = 0; i < graph[current_edge].size(); i++) {
        int cur = graph[current_edge][i];
        if (passed[cur] == false) {
            dfs(graph, passed, cur, num_of_comp, components);
        }
    }
}

int main() {
    ifstream fin("components.in");
    ofstream fout("components.out");
    int n, m;
    fin >> n >> m;

    vector <vector<int>> graphMatrix;
    vector<bool> passed_vertex;
    vector<int> components;

    graphMatrix.resize(n);
    passed_vertex.resize(n);
    components.resize(n);

    for (int i = 0; i < m; i++) {
        int vertex_x, vertex_y;
        fin >> vertex_x >> vertex_y;
        graphMatrix[vertex_x - 1].push_back(vertex_y - 1);
        graphMatrix[vertex_y - 1].push_back(vertex_x - 1);
    }

    int count = 0;
    int num_of_component = 1;

    for (int i = 0; i < graphMatrix.size(); i++) {
        if (passed_vertex[i] == false) {
            dfs(graphMatrix, passed_vertex, i, num_of_component, components);
            num_of_component++;
            count++;
        }
    }

    fout << count << endl;
    for (int i = 0; i < components.size(); i++) {
        fout << components[i] << " ";
    }

    return 0;
}