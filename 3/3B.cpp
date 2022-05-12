// Реализация пирамидальной сортировки на C++
#include <iostream>
#include <fstream>

using namespace std;

// процедура для преобразования подкучи в двочиное дерево
// индексом в arr[]. n - размер кучи

void siftDown(int array[], int lengthArray, int i)
{
    int largest = i; //наибольший элемент - корень

    int left = 2*i + 1; // левый ребенок 2i+1
    int right = 2*i + 2; // правый ребенок 2i + 2

    // если левый дочерний элемент больше чем значение корня
    if (left < lengthArray && array[left] > array[largest])
        largest = left;

    // если правый дочерний элемент больше чем значение корня
    if (right < lengthArray && array[right] > array[largest])
        largest = right;

    // если самый большой элемент не корень
    if (largest != i)
    {
        swap(array[i], array[largest]);

        //рекурсивно преобразуюем в двочиную кучу поддерево
        siftDown(array, lengthArray, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int array[], int lengthArray)
{
    // Построение кучи (перегруппируем массив)
    for (int i = lengthArray / 2 - 1; i >= 0; i--)
        siftDown(array, lengthArray, i);

    // Один за другим извлекаем элементы из кучи
    for (int i=lengthArray-1; i>=0; i--)
    {
        swap(array[0], array[i]); // перемещаем текущий корень в конец
        siftDown(array, i, 0); // вызываем процедуру siftDown на уменьшенной куче
    }
}


void printArray(int array[], int n)
{
    for (int i=0; i<n; ++i)
        cout << array[i] << " ";
    cout << "\n";
}

int main()
{
    int n;
    ifstream fileInput("sort.in");
    fileInput >> n;
    int array[n];
    for (int i = 0; i < n; i++){
        fileInput >> array[i];
    }
    fileInput.close();

    heapSort(array, n);

    ofstream fileOutput("sort.out");
    for (int i = 0; i < n; i++){
        fileOutput << array[i] << " ";
    }
}