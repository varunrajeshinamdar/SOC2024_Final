#include<iostream>
using namespace std;

int main(){ 
    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n,target,first=-1,second;
        cin >> n >> target;

        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j] == target){
                    first=i;
                    second=j;
                    break;
                }
                
            }
        }
        if(first != -1){
            cout << first << ' ' << second << endl;
        }else cout << -1 << ' ' << -1 << endl;
    }
}