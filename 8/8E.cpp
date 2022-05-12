#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

void bfs(vector<vector<int> > &graph, vector<bool> &passed, vector<int> &graphLength, int begin) {
    queue<int> graphQueue;
    graphQueue.push(begin);
    graphLength[begin] = 0;
    passed[begin] = true;

    while (graphQueue.empty() == false) {

        int frontTemp = graphQueue.front();
        graphQueue.pop();

        for (int i = 0; i < graph[frontTemp].size(); i++) {
            if (passed[graph[frontTemp][i]] == false) {
                graphLength[graph[frontTemp][i]] = graphLength[frontTemp] + 1;
                passed[graph[frontTemp][i]] = true;
                graphQueue.push(graph[frontTemp][i]);
            }
        }
    }
}

int main() {
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");
    int n, m;
    fin >> n >> m;

    vector <vector<int>> graphMatrix(n);
    vector<bool> passedVertex(n);
    vector<int> graphLength(n);

//    graphMatrix.resize(n);
//    passedVertex.resize(n);
//    graphLength.resize(n);


    for (int i = 0; i < m; i++) {
        int vertex_x, vertex_y;
        fin >> vertex_x >> vertex_y;
        graphMatrix[vertex_x - 1].push_back(vertex_y - 1);
        graphMatrix[vertex_y - 1].push_back(vertex_x - 1);
    }

    bfs(graphMatrix, passedVertex, graphLength, 0);

    for (int i = 0; i < graphLength.size(); i++) {
        fout << graphLength[i] << " ";
    }

    return 0;
}