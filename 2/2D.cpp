#include <iostream>
#include <fstream>
using namespace std;
 
int main() {
    ifstream inputFile("antiqs.in");
    int countOfArray;
    cin >> countOfArray;
    int array[countOfArray];
    for(int i = 0; i < countOfArray; i++){
        array[i] = i + 1;
    }
    int item;
    for(int i=0 ;i < countOfArray; i++){
        item = array[i / 2];
        array[i / 2] = array[i];
        array[i] = item;
    }
    ofstream outputFile("antiqs.out");
    for(int i=0; i < countOfArray; i++){
        outputFile << array[i] << ' ';
    }
    return 0;
}