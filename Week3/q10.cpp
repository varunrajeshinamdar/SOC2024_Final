#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);        // or ios_base::sync_with_stdio(0)?
    cin.tie(0);
    cout.tie(0);

        int n; cin >> n;
        vector<string> strings(n);
        int count = 0;
        for(auto &it : strings) cin >> it;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                string concat = strings[i]+strings[j];
                if(concat.size()%2 == 0){
                    int sum1 = 0, sum2 = 0;
                    for(int i=0;i < concat.size()/2; i++) sum1 += concat[i];
                    for(int i=concat.size()/2;i<concat.size();i++) sum2 += concat[i];       // wrote concat.size()-1
                    if(sum1 == sum2) count++;
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(j != i){
        //             string concat = strings[j]+strings[i];              // was never told j>i, missed this
        //             if(concat.size()%2 == 0){                   // but now j from i+1, else double count at equality
        //                                                     // actually only exclue j==i
        //                 int sum1 = 0, sum2 = 0;
        //                 for(int i=0;i < concat.size()/2-1; i++) sum1 += concat[i];
        //                 for(int i=concat.size()/2;i<concat.size()-1;i++) sum2 += concat[i];
        //                 if(sum1 == sum2) count++;
        //             }
        //         }
        //     }
        // }
    cout << count << '\n';
    return 0;
}