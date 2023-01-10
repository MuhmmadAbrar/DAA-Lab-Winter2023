#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;

void printArray(char array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void insertionSort(char array[], int size) {
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
    string s;
    cin>>s;
    int len_st = s.length();
    char* data = new char[len_st + 1];
    strcpy(data, s.c_str());
    int size = sizeof(data) / sizeof(data[0]);
    clock_t timeStart = clock(); 
    insertionSort(data, size);
    float time=(float)(clock() - timeStart)/CLOCKS_PER_SEC;
    cout<<"The number of inputs: "<<len_st<<endl;
    cout << "Sorted string in ascending order:\n";
    printArray(data, size);
    cout<<"Time Taken is "<<time<<"s";
}


