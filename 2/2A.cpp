#include <fstream>
using namespace std;

void qsort(long long *array,int left,int right) {
    long long middle;
    middle = array[rand() % (right - left + 1) + left];
    int i=left;
    int j=right;

    int item=0;

    while(i<j) {
        while(array[i]<middle){
            i++;
        }
        while(array[j]>middle){
             j--;
        } 

        if(i<=j){
            item=array[i];
            array[i]=array[j];
            array[j]=item;
            i++;
            j--;
        }
        
    }
    
    if(left<j)
        qsort(array,left,j);

    if(right>i)
        qsort(array,i,right);
}
 
 
int main(){ 

    ifstream fileInput("sort.in");
    ofstream fileOutput("sort.out");
    int countOfArray;
    fileInput >> countOfArray;
    long long array[countOfArray];

    for(int i = 0; i < countOfArray; i++)
    {
        fileInput >> array[i];
    }

    qsort(array, 0, countOfArray - 1);

    for(int i = 0; i < countOfArray; i++)
    {
        fileOutput << array[i] << " ";
    }

    fileInput.close();
    fileOutput.close();
    return 0;
}