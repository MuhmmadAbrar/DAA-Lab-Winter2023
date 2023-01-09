#include<iostream>
#include<cmath>
using namespace std;
void input(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void print(int A[],int B[],int n)
{
    for(int u=0;u<n;u++)
    {
        cout<<A[u]<<","<<B[u]<<endl;
    }
    cout<<endl;
}
void dist(int A[],int B[],int D[],int n )
{
    for(int i=0;i<n;i++)
    {
        D[i]=sqrt(pow(A[i],2)+pow(B[i],2)) ; 
    }
}

void insertion_sort(int arr[],int A[],int B[],int n)
{
    int k;
    for(int u=1;u<n;u++)
    {
        int key=arr[u];
        int k2=A[u];
        int k3=B[u];
        int v=u-1;

        while(key<arr[v] && v>=0)
        {
            if(arr[v]==k)
            {
                int pos=v;
            }
            arr[v+1]=arr[v];
            A[v+1]=A[v];
            B[v+1]=B[v];

            --v;
        }
        arr[v+1]=key;
        A[v+1]=k2;
        B[v+1]=k3;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int X[n],Y[n],D[n];
    input(X,n);
    input(Y,n);
    dist(X,Y,D,n);
    insertion_sort(D,X,Y,n);
    print(X,Y,n);
}