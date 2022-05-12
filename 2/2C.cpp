#include <iostream>
#include <fstream>
using namespace std;
long long answer = 0, n, coppy_array[300000], array[300000];
void merge(long first, long last){
    long middle, start, dec_mid;
    long j = 0, i = 0;


    middle = (first + last) / 2;
    start = first;
    dec_mid = middle + 1;
    long inversion = middle - first + 1;

    while(start + i <= middle && dec_mid + j <= last){
       if(array[start + i] <= array[dec_mid + j]){
           coppy_array[i + j] = array[start + i];
           i++;
       }
       else{
           coppy_array[i + j] = array[dec_mid + j];
           answer += inversion - i;
           j++;
       }
    }
    while(start + i <= middle){
       coppy_array[i + j] = array[start + i];
       i++;
    }
    while(dec_mid + j <= last){
       coppy_array[i + j] = array[dec_mid + j];
       j++;
    }

     for (i = 0; i < last - start + 1; i++){
        array[start + i] = coppy_array[i];
     }


}

void merge_sort(long first, long last)
{

    if (first < last)
    {
        long middle = (first + last) / 2;

        merge_sort(first, middle);
        merge_sort(middle + 1, last);
        merge(first, last);
    }
}


int main()
{
    ifstream inputFile("inversions.in");
    ofstream outputFile("inversions.out");
    inputFile >> n;



    for(int i = 0; i < n; i++)
    {
        inputFile >> array[i];
    }

    merge_sort(0, n - 1);

    outputFile<< answer;


    inputFile.close();
    outputFile.close();
    return 0;
}