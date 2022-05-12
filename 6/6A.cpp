#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int HashF(int value) {
    return abs(value % 1000000);
}

int exists(vector<vector<int>> &Table, int value) {
    int hashIndex = HashF(value);
    for (int i = 0; i < Table[hashIndex].size(); i++) {
        if (Table[hashIndex][i] == value) {
            return 1;
        }
    }
    return 0;
}

void insert(vector<vector<int>> &Table, int value) {
    int Index = HashF(value);
    if (exists(Table, value) == 0) {
        Table[Index].push_back(value);
    }
}

void del_elem(vector<vector<int>> &Table, int value) {
    int hashIndex = HashF(value);
    for (int i = 0; i < Table[hashIndex].size(); i++) {
        if (Table[hashIndex][i] == value) {
            Table[hashIndex].erase(Table[hashIndex].begin() + i);
        }
    }
}

int main() {
    ifstream fin("set.in");
    ofstream fout("set.out");
    int length = 1000000;
    vector<vector<int>> Table(length, vector<int>());
    string command;
    int value;
    while (fin >> command) {
        fin>>value;
        if (command == "insert") {
            insert(Table, value);
        } else if (command == "exists") {
            if (exists(Table, value)) {
                fout << "true" << endl;
            } else {
                fout << "false" << endl;
            }
        } else if (command == "delete") {
            del_elem(Table, value);
        }
    }
    fin.close();
    fout.close();
    return 0;
}