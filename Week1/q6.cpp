#include<bits/stdc++.h>
using namespace std;        // find meaning of rotated array

int main(){
    int t; cin >> t;
    for(int a=0;a<t;a++){       // testing code for all possible cases : keeping array of 1 to 6, vary the start element from 1 to 6. sim maybe do for big enough odd no array, etc
        int n; cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];

        int min = arr[0];
        int low=0,high=n-1;             // initial mistake : had put high = n-1; out of range array access doesnt even give any error, so be very careful

        while(low<=high){
            int mid = (low+high)/2;                    // standard is that low + (high-low)/2 is preferred since it avoid overflow problems when both high&low are large numbers near the int's limit
            if(arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1]){
                min = arr[mid];
                break;
            }
            if(arr[mid] > arr[high]) low = mid+1;
            else high = mid -1;
        }

        cout << min << endl;                                // new interesting usage : while(t--){autom stops when t becomes 0} or arr[n++] types
    }
}

// for vectors directly do cin >> v[i], no need to take cin >> i and then v.push_back(i);
// try bineary search with high= mid and no mid==target checking req

/*      v.eff code

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return nums[low];
}

int main() {
    int t; // number of test cases
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n; // size of the array
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        cout << findMin(nums) << endl;
    }
    
    return 0;
}
*/