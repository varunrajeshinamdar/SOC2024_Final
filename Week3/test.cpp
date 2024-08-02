#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


int main(){
    pair <int,int> arr[3] = {{1,0},{0,1},{3,2}};
    sort(arr,arr+3);

    for(auto it : arr) cout << it.first << ' ' << it.second << '\n';
}