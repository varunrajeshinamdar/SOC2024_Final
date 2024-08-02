#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int n,int arr[]){
    for(int endIndex=n-1;endIndex>=1;endIndex--){
        for(int i=0;i<endIndex;i++){
            if(arr[i+1]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

vector<int> func(int n){        // dont forget <int> in return type
    vector<int> v;              // "function" is a sort of keyword so using it doesnt work
    v.push_back(n);
    return v;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //vector<int> v = {1,2,3};
    //cout << v.back() << ' ' << v.front() << '\n';
    vector<int> v = func(3);
    cout << v.back() << ' ' << v.front() << '\n';

    return 0;
}