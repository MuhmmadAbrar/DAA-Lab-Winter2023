#include<iostream>
#include<ctime>
using namespace std;
 
int main()
{
	int n, i, j, max=-1, sum, imax, fmax;
	cout<<"\nEnter the number of data elements in the array: ";
	cin>>n;
    int a[n];
	for(i = 0; i < n; i++){
		cout<<"Enter element "<<i+1<<": ";
		cin>>a[i];
	}
    clock_t st = clock();
	for(i = 1; i < n+1; i++){
		sum = 0;
		for(j = 0; j < n; j++){
			if(j < i)
				sum += a[j];
			else
				sum = sum+a[j]-a[j-i];
			if(max < sum ){
				imax = j-i+1;
				fmax = j;
				max = sum;
			}
		}
	}
    
    double time_1 = (double)(clock()-st)/CLOCKS_PER_SEC;
    cout<<"\nThe Starting index is "<<imax<<"\nThe Ending index is "<<fmax<<endl;
	cout<<"\nThe maximum sub array is: ";
	for(i = imax; i <= fmax; i++)
		cout<<a[i]<<" ";
	cout<<"\nThe maximum sub-array sum is: "<<max;
    cout<<"\nThe time taken is: "<<time_1;
}