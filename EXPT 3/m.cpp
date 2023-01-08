#include <cmath>
#include <iostream>
using namespace std;
class Sort{
    public:
    void mergesort(int a[],int low,int high){
        if (low<high){
            int mid=floor((low+high)/2);
            mergesort(a,low,mid);
            mergesort(a,mid+1,high);
            int value=merge(a,low,mid,high);
        }
        printarray(a,high);
    }

    void printarray(int a[],int s){
        cout<<"Array"<<endl;
        for(int i=0;i<s;i++){
            cout<<a[i]<<endl;
        }
    }

    int merge(int a[],int low,int mid,int high){
        int b[high+1];
        int i=low;
        int j=mid+1;
        int k=low;
        while(i<=mid && j<=high){
            if (a[i]<=a[j]){
                b[k]=a[i];
                k++;
                i++;
            }
            else{
                b[k]=a[j];
                k++;
                j++;
            }
        }
        for(i;i<=mid;i++){
            b[k]=a[i];
            k++;
        }
        for(j;j<=high;j++){
            b[k]=a[j];
            k++;
        }
        for(int c=0;c<=high;c++){
            a[c]=b[c];
        }
    }
};

int main() {
    Sort g;
    int a[100];
    int n;
    cout<<"Enter the no. of elements in array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    g.mergesort(a,0,n-1);
}