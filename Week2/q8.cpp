#include<bits/stdc++.h>
//#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n; cin >> n;
        string s;
        cin >> s;
        int minm = n;                    // *** dont use "min" as naming because then we cant use that function min() when needed

        for(int l=n;l>=1;l--){                          // starting reverse so no need of min function
            if(n%l == 0){
                string k1,k2,duplicate1,duplicate2;
                for(int i=0;i<l;i++){
                    k1 += s[i]; 
                    k2 += s[n-l+i];                     // not s[n-1-i]
                }            

                int factor = n/l;
                while(factor--){
                    duplicate1 += k1;             // (n/l)-- doesnt work, lvalue required
                    duplicate2 += k2;
                }
                int count1 = 0, count2 = 0;

                for(int i=0;i<n;i++){
                    if(duplicate1[i] != s[i]) count1++;
                    if(duplicate2[i] != s[i]) count2++;
                }
                int count = min(count1,count2);
                if(count <= 1) minm = l;
            }
        }
        cout << minm << '\n';
    }
    return 0;
}