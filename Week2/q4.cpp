#include<bits/stdc++.h>
using namespace std;            // doubt check how 1+2+3... = 1.3.5.... thing while forming pairs

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

int main(){                 // argument of vector itself can also be a pair
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n ; cin >> n;
        int arr[2*n];
        for(int i=0;i<2*n;i++) cin >> arr[i];

        bubbleSort(2*n,arr);
        int xcoord[n],ycoord[n];
        for(int i=0;i<n;i++){
            xcoord[i] = arr[i];
            ycoord[i] = arr[i+n];
        }
        int s = arr[2*n-1] + arr[n-1] - arr[n] - arr[0];
        cout << s << '\n';
        for(int i=0;i<n;i++){
            cout << xcoord[i] << ' ' << ycoord[i] << '\n';
        }
    }

    return 0;
}