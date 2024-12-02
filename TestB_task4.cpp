#include <iostream>
#include <cmath>

using namespace std;

void ReadArray(float array[], int size);
void PrintArray(float array[], int size);
bool IsSorted(float array[], int size);
int NumbersToClear(float array[], int size);
void ClearArray(float array[], int& size);



int main()
{
	float array[5] = {};
	int size = sizeof(array) / sizeof(array[0]);

	cout << "Enter 5 float numbers" << endl;

	ReadArray(array, size);
	PrintArray(array, size);

	if (IsSorted(array, size)) {
		cout << "It is sorted in ascending way! \n\n";
	}
	else {
		cout << "It is not sorted in ascending way! \n\n";
	}

	int numbersRemoved = NumbersToClear(array, size);
	cout << "Number of elements that have to be removed so the array can become sorted: " << numbersRemoved << "\n\n";

	ClearArray(array, size);
	PrintArray(array, size);



}

//Takes the input for the elements of the array
void ReadArray(float array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter a number: ";
		cin >> array[i];
	}
	cout << endl << endl;
}

void PrintArray(float array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
}

//Checks if the array is in ascending order
bool IsSorted(float array[], int size) {
	bool ascending = true;
	
	for (int i = 0; i < size - 1; i++) {
		if (array[i] > array[i + 1]) {
			ascending = false;
		}
	}

	return ascending;
}

//Checks how many numbers should be removed from the array so it can become sorted in ascending way
int NumbersToClear(float array[], int size) {
	int numbersToBeRemoved = 0;
	int a = 1;
	int i = 0;
	
	while (i < size - 1) {
		if (array[i] > array[a]) {
			numbersToBeRemoved++;
			//This will be used if the last number in the array is smaller than the previous one
			if (a >= (size - 1)) {
				i = a;
			}
			a++;
		}
		else {
			i = a;
			a++;
		}
	}


	return numbersToBeRemoved;
}

//This will be used for the elements that have to be cleared so the array can be sorted in ascedning way
void ClearArray(float array[], int& size) {
	int newSize = 1;
	float newArray[5] = {};			//This is a temporary array that will store the needed numbers

	newArray[0] = array[0];
	int a = 1;
	for (int i = 0; i < size - 1; i++) {
		if (array[i] <= array[i + a]) {
			newArray[newSize++] = array[i + 1];
		}
	}

	//This rewrites the left numbers in the original array
	for (int i = 0; i < newSize; i++) { 
		array[i] = newArray[i];
	}

	size = newSize;

}



