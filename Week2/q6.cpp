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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
        int n,d;
        cin >> n >> d;
        int p[n];
        for(int i=0;i<n;i++) cin >> p[i];

        int teamcount = 0;
        bubbleSort(n,p);
        while(true){
            long long sum = 0;
            int count = 0;
            while(sum<=d && n-count>=1){
                sum+=p[n-1];
                count++;
            }
            n -= count;       // first n-1 and last element removed
            if(n<=0) break;

            for(int i=0;i<n;i++) p[i] = p[count+i-1];
            teamcount++;
        }
        cout << teamcount << '\n';
        return 0;
}