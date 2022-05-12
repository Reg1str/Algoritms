#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct country_name{
    string country;
    string name;
};

country_name array[300000], coppy_array[300000];

void merge(long first, long last){
    long middle, start, final;
    long j = 0, i = 0;


    middle = (first + last) / 2;
    start = first;
    final = middle + 1;


    while(start + i <= middle && final + j <= last){
       if(array[start + i].country <= array[final + j].country){
           coppy_array[i + j] = array[start + i];
           i++;
       }
       else{
           coppy_array[i + j] = array[final + j];
           j++;
       }
    }
    while(start + i <= middle){
       coppy_array[i + j] = array[start + i];
       i++;
    }
    while(final + j <= last){
       coppy_array[i + j] = array[final + j];
       j++;
    }

     for (i = 0; i < last - start + 1; i++){
        array[start + i] = coppy_array[i];
     }


}

void merge_sort(long first, long last){
    if (first < last){
        long middle = (first + last) / 2;

        merge_sort(first, middle);
        merge_sort(middle + 1, last);
        merge(first, last);
    }
}



int main(){
    ifstream inputFile("race.in");
    ofstream outputFile("race.out");
    string count;
    int n;
    inputFile >> n;
    

    for (int i = 0; i < n; i++) {
        inputFile >> array[i].country >> array[i].name;
   
    }

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++){
        if (count != array[i].country){
            outputFile << "=== " << array[i].country << " ===" << "\n";
            count = array[i].country;
        }
        outputFile << array[i].name << "\n";
    }
    inputFile.close();
    outputFile.close();
    return 0;
}