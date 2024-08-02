#include<bits/stdc++.h>
using namespace std;

int solve(int l,int r,int p[]){
    if(r-l == 0) return 0;
    int mid = (l+r+1)/2, ans = 0;
    int lmax = *max_element(p+l,p+mid), rmax = *max_element(p+mid,p+r+1);

    if(lmax > rmax){
        ans++;
        for(int i=0;i<mid-l;i++) swap(p[i+l],p[mid+i]);     // dont get carried away be ex you took, i did p[i+1]
    }                  // mid-l not mid-1                   standard divide type sum******
    return (ans + solve(l,mid-1,p) + solve(mid,r,p));
}

// remember many times input problems occur not just becoz of wrong input lines, but any overall code mistake

int main(){
    ios::sync_with_stdio(0);        // or ios_base::sync_with_stdio(0)?
    cin.tie(0);                     // also instead of 0, can type false or NULL or nullptr
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        int m; cin >> m;
        int p[m+1];
        for(int i=1;i<=m;i++) cin >> p[i];

        int moves = solve(1,m,p), boo =1;
        for(int i=1;i<m;i++){
            if(p[i]>p[i+1]) boo =0;
        }
        if(boo) cout << moves << '\n';
        else cout << "-1" << '\n';

    }

    return 0;
}