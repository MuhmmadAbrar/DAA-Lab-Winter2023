#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
int main(){
    clock_t tStart = clock();    
    vector<int> arr1;
    vector<int> arr2;
    int n,ele;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ele;
        if(ele<0){
            arr1.push_back(ele);
        }
        else{
            arr2.push_back(ele);
        }
    }
    for(int j=1;j<arr1.size();j++){
        int key=arr1[j];
        int i=j-1;
        while(key>arr1[i]&&(i>=0)){
            arr1[i+1]=arr1[i];
            i=i-1;
        }
        arr1[i+1]=key;
    }
    for(int j=1;j<arr2.size();j++){
        int key = arr2[j];
        int i = j-1;
        while((i>=0)&&(arr2[i]>key))
        {
            arr2[i+1] = arr2[i];
            i = i-1;
        }
        arr2[i+1] = key;
    }
double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	cout<<"Time taken is "<<time1<<endl;
   for(int i=0;i<arr1.size();i++){
    cout<<arr1[i];
   }
   for(int i=0;i<arr2.size();i++){
    cout<<arr2[i];
   }
}

