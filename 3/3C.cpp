#include <fstream>
using namespace std;

string firstArray[1000], secondArray[1000];

//
void radixsort(int index, int stringCount)
{
	char firstLetter = 'a'; //
	int count = 0;
	for (int i = 0; i <= 26; i++){ // i <= 26 . 26
		for (int j = 0; j < stringCount; j++)
		{
			if (firstArray[j][index] == firstLetter){
				secondArray[count] = firstArray[j];
				count++;
			}
		}
		firstLetter++; // a b, b c
	}
	for (int i = 0; i < stringCount; i++) {
		firstArray[i] = secondArray[i]; 
	}
}

int main()
{
	ifstream inputFile("radixsort.in");
	ofstream outputFile("radixsort.out");
	long n, m, k; // n - - m - k -
	inputFile >> n >> m >> k;

	for (int i = 0; i < n; i++) { 
		inputFile>>firstArray[i];
	}

	for (int i = m - 1; i >= m - k; i--) { 
		radixsort(i, n); 
	}

	for (int i = 0; i < n; i++) { 
		outputFile<<firstArray[i]<< '\n';
	}
	return 0;
}