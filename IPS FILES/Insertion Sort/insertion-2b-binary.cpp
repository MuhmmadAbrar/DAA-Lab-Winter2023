#include<iostream>
#include<ctime>
using namespace std;
int bSearch(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return bSearch(arr, l, mid - 1, x);
 
        return bSearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main(){
    int n,k,ele;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>ele;  
        arr[i]=ele;
    }
    cin>>k;
    clock_t st=clock();
    for(int i=1;i<n;i++){
        int key;
        int j=i-1;
        key=arr[i];
        while((j>=0)&&(arr[j]>key)){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    int index = bSearch(arr,0,n-1,k); 
    if(index != -1){
        cout<<"Element not found.";
    }   
    else{
        cout<<"Element position is "<<index+1;
    }
    double time1=(double)(clock() - st)/CLOCKS_PER_SEC;
	cout<<"Time taken is "<<time1<<endl;
}

