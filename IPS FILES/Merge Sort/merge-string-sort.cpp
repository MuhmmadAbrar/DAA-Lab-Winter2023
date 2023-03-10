#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include<bits/stdc++.h>

using namespace std;

void merge(char array[], int const left, int const mid,
		int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, 
	indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left; 

	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

void mergeSort(char array[], int const begin, int const end)
{
	if (begin >= end)
		return;
	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

void printArray(char A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{   
    string s = "Sample String";
    const int length = s.length();
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    char* char_array = new char[length + 1];
    strcpy(char_array, s.c_str());

	cout << "Given string is ";
	printArray(char_array, length);

    clock_t st=clock();

	mergeSort(char_array, 0, length - 1);

	cout << "\nSorted string is ";
	printArray(char_array, length);
    
    double time1=(double)(clock() - st)/CLOCKS_PER_SEC;
	cout<<"\n Time taken is "<<time1<<"s"<<endl;

	return 0;
}


