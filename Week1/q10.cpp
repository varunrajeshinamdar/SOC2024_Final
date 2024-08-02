#include<iostream>
using namespace std;

int maximum(int arr[],int k,int start){
    int max=arr[start];
    for(int i=start+1;i<=start+k-1;i++){
        if(arr[i]>max) max = arr[i];
    }
    return max;
}

int main(){                     // see for loops which iterate just by writing 2 words
    int t; 
    cin >> t;
    for(int a=0;a<t;a++){       //try using deque??
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        int max[n-k+1];

        for(int start=0;start+k-1<n;start++){
            max[start] = maximum(arr,k,start);
        }
        
        for(int i=0;i<n-k+1;i++) cout << max[i] << ' ';
    }

    return 0;
}