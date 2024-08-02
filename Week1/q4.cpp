#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a=0;a<t;a++){
        int n; cin >> n;
        int arr[n];
        for(int b=0;b<n;b++) cin >> arr[b];

        int maxsum = arr[0],currentsum = 0;

        for(int i=0;i<n;i++){
            currentsum+=arr[i];
            if(currentsum<0) currentsum = 0;
            if(currentsum > maxsum) maxsum = currentsum;

        }
        cout << maxsum << endl;
    }
}