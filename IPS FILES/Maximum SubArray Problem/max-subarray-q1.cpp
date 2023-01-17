#include<iostream>
#include<ctime>
using namespace std;

int maxSubArraySum(int a[], int size, int &start, int &end){
    int max_so_far = INT_MIN, max_ending_here = 0;
    int s = 0;
    start = 0;
    end = 0;
    for (int i = 0; i < size; i++){
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0){
            max_ending_here = 0;
            s = i + 1;
        }
    }
    return max_so_far;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(a)/sizeof(a[0]);
    int start,end;
    clock_t st = clock();
    int max_sum = maxSubArraySum(a, size, start, end);
    double time_1 = (double)(clock()-st)/CLOCKS_PER_SEC;
    cout << "Maximum sum of subarray is " << max_sum << endl;
    cout << "Start index: " << start << endl;
    cout << "End index: " << end << endl;
    cout << "Time taken is: " << time_1 <<"s"<<endl;
    cout << "And the subarray is: "<<endl;
    for(int i=start;i<=end;i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}
