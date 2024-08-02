#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n, count=0;
        cin >> n;               // forgot this line, huge problems
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                /*int l = log(arr[i])+arr[j]*log(2);
                int m = log(arr[j]) + arr[i]*log(2);
                if(l==m) count++;*/                         // integers wont work since extra counts due to truncation
                if( abs(log(arr[i])+arr[j]*log(2) - log(arr[j]) - arr[i]*log(2)) < 1e-7) count++;  // lot of time wasted because wrote the 3rd sign also as +
            }                                                                                      // also hadnt written abs
        }
        cout << count << '\n';
    }

    return 0;
}