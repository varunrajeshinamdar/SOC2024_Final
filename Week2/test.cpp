#include<bits/stdc++.h>
using namespace std;

int combination(int n,int r){           // efficient way to calc combs
    int prod = 1;
    for(int i=1;i<=r;i++){
        //prod *= (n-i+1)/i;            // causes error due to integer truncation
        prod *= n-i+1;
        prod /= i;
    }
    return prod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // set<int> st = {1,2,3,4};
    // int* a = st.begin()+3;
    // cout << *(st.rbegin()) << '\n' ;
    // cout << *a;



    // set<int> v = {5,4,3,2,1};
    // sort(v.begin(),v.begin()+5);
    // v.erase(v.begin(),v.begin()+2);
    // for(auto it : v) cout << it << ' ';

    vector<int> s = {1,2,3};
    auto x = s.begin();
    advance(x,2);
    cout << *x;

}