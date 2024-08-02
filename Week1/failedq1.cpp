#include<iostream>
using namespace std;

int main(){
    int t; cin >> t;
    for(int a=0;a<t;a++){
        int i=0,j=0,sum=0;         // vimp standard : cant start from j=-1 because then 1st array element becomes ND

        int n,k;
        cin >> n >> k;
        int nums[n];
        for(int j=0;j<n;j++) cin >> nums[j];

        while(sum<k){
            if(j>=n){                   // if block above sum+=
            cout << "-1" << endl;
            j++;
            break;
            }
            sum+=nums[j];
            j++;
            
        }
        if(j==n+1) continue;      // dont forget == not =

        int l=j;
        j--;
        while(j<n){
            if(sum >= k && i<j){        // see && i<j,      initially had done sum-nums[i]>=k which is wrong
                sum -= nums[i];
                i++; l -= 1;
            }else{
                if(j<n){sum += nums[j];
                j++; l += 1;}
            }
        }
        cout << l+1 << endl;

    }
}