#include <fstream>
#include <vector>

using namespace std;
ifstream fileInput("map.in");
ofstream fileOutput("map.out");
struct item {
    string key;
    string value;
};

int function(string &input_word){ // Функция для хешированиея элементов
    int index=0;
    int kNum = 41;
    for (int i = 0; i < input_word.size(); i++) {
        int string = 0;
        if (input_word[i] - 'b' >= 0)
            string = input_word[i] - 'a';
        index= ((index + string) % 10000) * (kNum + 1) % 10000;
        kNum = ((kNum*kNum)+1)%10000;
    }
    return index;
}


void get(vector<vector<item>> &table, string &input_word) {
    int hashIndex = function(input_word);
    for (int i = 0; i < table[hashIndex].size(); i++) {
        if (table[hashIndex][i].key == input_word) {
            fileOutput << table[hashIndex][i].value << "\n";
            return;
        }
    }
    fileOutput << "none" << "\n";
}

void put(vector<vector<item>> &table, string &key, string &input_word) {
    int index = function(key);
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i].key == key) {
            table[index][i].value = input_word;
            return;
        }
    }
    table[index].push_back({key, input_word});
}

void delete_item(vector<vector<item>> &table, string &input_word) {
    int hashIndex = function(input_word);
    for (int i = 0; i < table[hashIndex].size(); i++) {
        if (table[hashIndex][i].key == input_word) {
            table[hashIndex].erase(table[hashIndex].begin() + i);
            return;
        }
    }
}

int main() {
    vector<vector<item>> table(100001, vector<item>());
    string command;
    while (fileInput >> command) {
        if (command == "put") {
            string key;
            string word;
            fileInput >> key >> word;
            put(table, key, word);
        } else if (command == "get") {
            string key;
            fileInput >> key;
            get(table, key);
        } else {
            string key;
            fileInput >> key;
            delete_item(table, key);
        }
    }
    return 0;
}