#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int m, n, x, y;
    fin >> n >> m;

    int graphMartix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graphMartix[i][j] = 0;
        }
    }

    bool result = false;
    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        if (graphMartix[x - 1][y - 1] == 1 || graphMartix[y - 1][x - 1] == 1) {
                result = true;
                break;
        }
        graphMartix[x-1][y-1] = 1;

    }



    if (result) {
        fout << "YES" << endl;
    } else {
        fout << "NO" << endl;
    }
}