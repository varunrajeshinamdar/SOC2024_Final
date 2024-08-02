#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int a[n];
        for(auto &it : a) cin >> it;
        pair<int,int> queries[k];
        for(auto &it : queries) cin >> it.first >> it.second;

        map<int,set<int>> mpp;
        for(int i=0;i<n;i++) mpp[a[i]].insert(i);       // dont forget T.C. of DS itself which you are using, ex: here map =logn. so loop is nlogn not just n.

        for(int i=0;i<k;i++){
            if(mpp[queries[i].second].size()==0 || mpp[queries[i].first].size()==0){
                cout << "no\n";
                continue;
            }else if(*mpp[queries[i].first].begin() < *(mpp[queries[i].second].rbegin())){
                cout << "yes\n";
            }else{
                // *** forgot this last else, if iterator is >= then also no, so missed cases
                cout << "no\n";
            }
        }
    }

    return 0;
}



/*#include<bits/stdc++.h>
using namespace std;

int startindex(int stations[],int aj,int n){
    int minm = n;
    for(int i=0;i<n;i++) if(stations[i] == aj) minm = min(minm,i);      // mistake typed '='
    return minm;
}

int endindex(int stations[],int bj,int n){
    int maxm = -1;                                                      // so that wrong if doesnt exist, same for above MAKES A HUGE DIFFERENCE, MADE THE CODE WORK
    for(int i=0;i<n;i++) if(stations[i] == bj) maxm = max(maxm,i);
    return maxm;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n,k; cin >> n >> k;

        int stations[n];
        for(int i=0;i<n;i++) cin >> stations[i];
        int aj[k],bj[k];
        for(int i=0;i<k;i++) cin >> aj[i] >> bj[i];

        for(int i=0;i<k;i++){
            if(startindex(stations,aj[i],n) <= endindex(stations,bj[i],n)) cout << "yes" << '\n';
            else cout << "no" << '\n';
        }
    }

    return 0;
}*/