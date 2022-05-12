#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int m, n, graph_vertex_1, graph_vertex_2;
    fin >> n >> m ;

    int graphMartix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graphMartix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        fin >> graph_vertex_1 >> graph_vertex_2;
        graphMartix[graph_vertex_1 - 1][graph_vertex_2 - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fout << graphMartix[i][j] << " ";
        }
        fout << endl;
    }
}