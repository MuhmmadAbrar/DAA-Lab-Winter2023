#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void sort(vector<int> &v){
    for (size_t j = 1; j < v.size(); j++){
        int key = v[j];
        int i = j - 1;
        while (i >= 0 && v[i] > key)
        {
        v[i + 1] = v[i];
        i--;
        }
        v[i + 1] = key;
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v1;
    char str[n];
    char sorted_str[n];
    clock_t timeStart = clock(); 
    for(int i = 0; i<n; i++){
        cin>>str[i];
        v1.push_back(str[i]);
    }
    sort(v1);
    for(int i = 0; i<n; i++) sorted_str[i] = v1[i];
    double time=(double)(clock() - timeStart)/CLOCKS_PER_SEC;
    cout<<"\nTime taken is "<<time<<endl;
    return 0;
}
