#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);        // or ios_base::sync_with_stdio(0)?
    cin.tie(0);                     // also instead of 0, can type false or NULL or nullptr
    cout.tie(0);

    int n,t; cin >> n >> t;
    int a[n];
    for(int i=1;i < n;i++) cin >> a[i];

    int current = 1;
    while(current < t) current += a[current];
    if(current == t) cout << "YES" << '\n';
    else cout << "NO\n";

    return 0;
}