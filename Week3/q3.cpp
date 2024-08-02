#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(auto &it : arr) cin >> it;

        long long int sum = 0, minim = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            minim = min(minim,sum);
        }
        cout << sum - 2*minim << "\n";
    }

    return 0;
}