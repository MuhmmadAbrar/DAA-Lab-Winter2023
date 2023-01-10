#include <iostream>
using namespace std;

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0) {
        array[j + 1] = array[j];
        --j;
        }
        array[j + 1] = key;
    }
}

int main() {
    int data[] = {5,7,4,3,6,2};
    cout << "Given array: \n";
    int size = sizeof(data) / sizeof(data[0]);
    printArray(data,size);
    insertionSort(data, size);
    cout << "Insertion sort in ascending order:\n";
    printArray(data, size);
}


