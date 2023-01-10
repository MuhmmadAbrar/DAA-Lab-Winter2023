#include<iostream>
#include<ctime>
using namespace std;

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
    
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            cout<<"Element position is"<<i+1<<'\n';
        }
    }
    
    double time1=(double)(clock() - st)/CLOCKS_PER_SEC;
	cout<<"Time taken is "<<time1<<endl;
}

