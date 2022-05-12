#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;
    int graphMatrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> graphMatrix[i][j];
        }
    }

    bool result = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graphMatrix[i][j] == 1) {
                if (graphMatrix[j][i] != 1 || i==j){
                    result = false;
                }
            }
        }
    }

    if (result){
        fout << "YES" << endl;
    }
    else {
        fout << "NO" << endl;
    }


}
