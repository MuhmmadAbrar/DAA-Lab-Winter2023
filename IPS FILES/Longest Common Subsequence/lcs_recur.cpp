#include<iostream>
#include<cstring>
using namespace std;

int lcs(string A, string B, int a, int b){
    if(a==0 || b==0){
        return 0;
    }
    if(A[a-1]==B[b-1]){
        return 1+lcs(A,B,a-1,b-1);
    }
    else{
        return max(lcs(A,B,a-1,b),lcs(A,B,a,b-1));
    }
}

int main(){
    string A = "APPLE";
    string B = "BALL";
    cout<<"The length of the longest subsequence is "<<lcs(A,B,5,4);
}
