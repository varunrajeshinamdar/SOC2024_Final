#include<iostream>
using namespace std;

int main(){
    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n,m;
        cin >> n >> m;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];     // xor is keyword in c++ so dont use that, doesnt work

        int count=0;                            // smtg related to hash maps??
        for(int start=0;start<n;start++){
            for(int end=start;end<n;end++){
                int XOR = arr[start];
                for(int i=start+1;i<=end;i++){
                    XOR = XOR^arr[i];
                }
                if(XOR==m) count++;
            }
        }
        cout << count << endl;
    }

    return 0;

}