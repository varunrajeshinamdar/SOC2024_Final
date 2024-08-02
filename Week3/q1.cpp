#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n,0), x(n,0);
        for (auto &it : a) cin >> it;       // must pass by reference else not stored
        for (auto &it : x) cin >> it;
        vector<long long> s(n + 1);
        for (int i = 0; i < n; ++i) s[abs(x[i])] += a[i];
        bool ok = true;
        long long lft = 0;
        for (int i = 1; i <= n; ++i) {
        lft += k - s[i];
        ok &= (lft >= 0);
        }
        cout << (ok ? "YES" : "NO") << '\n';
  }
}


/*
#include<bits/stdc++.h>
using namespace std;

int minDist(vector<int> coords,int n){
    int minm = n+1,minIndex;
    for(int i=0;i<coords.size();i++){

        if(abs(coords[i]) < minm){
            minm = abs(coords[i]);      // forgot abs() here
            minIndex = i;
        }
    }
    return minIndex;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> health(n), coords(n);

        for(int i=0;i<n;i++) cin >> health[i];
        for(int i=0;i<n;i++) cin >> coords[i];
        bool dead = 0;

        while(!dead && !health.empty()){
            int bullets = k;
            while(bullets--){
                int currentIndex = minDist(coords,n);
                health[currentIndex]--;
                if(health[currentIndex] == 0){
                    health.erase(health.begin()+currentIndex);    // &health[currentIndex] not working
                    coords.erase(coords.begin()+currentIndex);      // health.begin() wont work
                }
            }
            for(int i=0;i< coords.size(); i++){
                if(coords[i]<0) coords[i]++;
                else coords[i]--;
            }
            dead = binary_search(coords.begin(),coords.end(),0);
        }
        if(health.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;

}
*/