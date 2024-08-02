#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);        // or ios_base::sync_with_stdio(0)?
    cin.tie(0);                     // also instead of 0, can type false or NULL
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        int n,e; cin >> n >> e;
        vector<int> a(n+1);
        for(int i=1;i<n+1;i++) cin >> a[i];
        int count = 0;

        for(int i=1;i<=n;i++){
            int kmax=1;
            while(i+e*kmax <= n){
                kmax++;
            }
            kmax--;
            for(int k=1;k<=kmax;k++){
                bool prime = 1;
                for(int z=0;z<=n;z++){
                    if(a[i+z*j] !=1) prime = 0;
                }
                if(prime) count++;
            }

        }
        cout << count << '\n';

    }

    return 0;
}