#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void removeDuplicates(int arr[], int& n) {
    unordered_set<int> seen;
    int j = 0; // To track the index of the modified array

    for (int i = 0; i < n; i++) {
        // Check if the current element is not in the set
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]); // Insert the element into the set
            arr[j++] = arr[i]; // Add element to modified array
        }
    }

    n = j; // Update the size of the array
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n; cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        sort(arr,arr+n);
        int N=n,length=0,maxl=0;

        /*for(int i=0;i<n;i++){           // mistake : i<N
            for(int j=i+1;j<n;j++){
                if(arr[i] == arr[j]){
                    n--;
                    for(int a=j;a<n;a++) arr[a] = arr[a+1];         // not <N
                    j--;            // to again check the new incomer
                }
            }
        }*/
        removeDuplicates(arr,n);

        int i=0,j=0;                // standard vv.confusing while loop(3 things), 1)argument j<n or n-1 & second condition
        // as standard? 2) difference < or <=n-1? 3)l and maxl lines should be placed where. all 3 must match mutually to give correct. TRICK; think in flow of code
        while(j<n && i<=j){
            if(arr[j]-arr[i] <= N-1){               // mistake , instead of n-1
                
                maxl = max(maxl,j-i+1);
                j++;
            }
            else i++;
        }
        cout << maxl << '\n';
    }

    return 0;
}