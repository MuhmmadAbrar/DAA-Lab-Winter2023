#include<iostream>
#include<ctime>
using namespace std;
int main(){
    clock_t start=clock();
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int j=1;j<n;j++){
        int key=arr[j];
        int i=j-1;
        while((i>=0)&&key<arr[i]){
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
    int arrfin[n];
    int i=0;
    while(arr[i]<0){
        i++;
    }
    int k=0;
    for(int j=i-1;j>=0;j--){
        arrfin[k]=arr[j];
        k++;
    }
    for(int j=i;j<n;j++){
        arrfin[k]=arr[j];
        k++;
    }
    cout<<"Time taken ="<<(double)(clock()-start)<<endl;
    for(int i=0;i<n;i++){
        cout<<arrfin[i];
    }
}