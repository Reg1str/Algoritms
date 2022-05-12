#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("isheap.in");
    ofstream outputFile("isheap.out");
    int n;
    inputFile>>n;
    int array[n];
    int i;


    for (int i=0;i<n;i++){
        inputFile>>array[i];
    }

    for (i=0;i<n;i++)
    {
        if (array[i]<=array[2*i+1] && array[i]<=array[2*i+2]);
        else
            break;

    }


    if(i < n / 2){
        outputFile << "NO";
    }
    else{
        outputFile << "YES";
    }

    inputFile.close();
    outputFile.close();

}