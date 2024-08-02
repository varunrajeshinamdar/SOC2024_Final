#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n; cin >> n;
        long long int arr[n];   //*** the ++ become v.big so long long was the only change that had to be made :)
        //int arrr[n];          no need of separate array, the edited values also do for second time
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        bool possible1 = 0,possible2 = 0;
        for(int index=0;index<=n-2;index++){

            /*if(index==n-2 && arr[n-2]<=arr[n-1]){ possible1 = 1;     // this should be above below block due to last index
                break;      // didnt write this
            }*/

            if(index==n-2){
                if(arr[n-2]<=arr[n-1]) possible1 =1;
                break;
            }

            if(arr[index]>arr[index+1]){
                while(arr[index]!=arr[index+1]){    // had done ==
                    arr[index+2]++;
                    arr[index+1]++;
                }
            }
            
        }
        
        for(int i=n-1;i>=1;i--){
            if(i==1){
                if(arr[1]>=arr[0]) possible2 = 1;       // forgot equality
                break;
            }

            if(arr[i]<arr[i-1]){
                while(arr[i]!=arr[i-1]){
                    arr[i-1]--;arr[i-2]--;
                }                
            }
        }
        if(possible1 || possible2) cout << "yes" << '\n';
        else cout << "no" << '\n';

    }

    return 0;
}