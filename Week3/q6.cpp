#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> c,int n){
    if(c[0] != 1) return 0;
    
    long long int runningSum = 1;
    for(int i=1;i<n;i++){
        if(c[i] > runningSum) return 0;
        runningSum += c[i];
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> c(n);
        for(int i=0;i<n;i++) cin >> c[i];
        sort(c.begin(),c.end());

        if(solve(c,n)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}