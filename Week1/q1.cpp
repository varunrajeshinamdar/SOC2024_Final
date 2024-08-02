#include<iostream>
using namespace std;

int main(){
    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n,k;
        cin >> n >> k;
        int nums[n],sum=0;
        for(int i=0;i<n;i++) cin >> nums[i];

        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum<k){
            cout << "-1" << endl;
            continue;
        }
        sum=0;
        int i,j,l=n;
        i=j=0;

        while(j<n){
            while(sum<k){
                sum+=nums[j];
                j++;
            }
            while(sum>=k){
                sum-= nums[i];
                if(j-i<l) l=j-i;
                i++;
            }
        }
        cout << l << endl;
    }
}


/*          ineff code

int main(){
    int t; cin >> t;
    for(int i=1;i<=t;i++){
        int n,k;
        cin >> n >> k;
        int nums[n];
        for(int j=0;j<n;j++) cin >> nums[j];

        int l=n+1;
        for(int length=1;length<=n;length++){
            for(int start=0;start<n && start+length<=n;start++){
                int sum = 0;
                for(int index=start;index<start+length;index++){
                    sum+=nums[index];
                    if(sum>=k && length<l) l= length;
                }
            }
        }
        if(l==n+1) cout << "-1" << endl;
        else cout << l << endl;
    }

    return 0;
}*/