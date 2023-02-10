#include <iostream>
#include <unordered_map>
#include<ctime>

using namespace std;

void subarray_with_sum_zero(int arr[], int n) {
    unordered_map<int,int> s;
    int sum = 0;
    int start = -1, end = -1;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            start = 0;
            end = i;
            break;
        }
        if (s.find(sum) != s.end()) {
            start = s[sum] + 1;
            end = i;
            break;
        }
        s[sum] = i;
    }
    if (start == -1) {
        cout << "-1 -1" << endl;
    } 
    else {
        cout <<"\nStart index is: "<<start << "\nEnd index is: " << end << endl;
    }
}

int main() {
    int arr[] = { 10, -3, 2, 4, -3, 5, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t st = clock();
    subarray_with_sum_zero(arr, n);
    double time_1 = (double)(clock()-st)/CLOCKS_PER_SEC;
    cout<<"\nThe time taken is: "<<time_1<<"s";
    return 0;
}