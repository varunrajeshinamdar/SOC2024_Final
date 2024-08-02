#include<iostream>
using namespace std;  

int main(){
    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n,target,first,second;
        cin >> n >> target;
        int i=0,j = n-1;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];

        while(i < j){
            if(arr[i]+arr[j]==target){          // mistake: did i+j
                first=i;second=j;
                break;                              // if not broken goes into inf loop***
            }else if(arr[i]+arr[j]<target) i++;
            else j--;                               // not j++
        }
        cout << '[' << first+1 << ',' << second+1 << ']' << endl;
    }
}

                                    // solved by method sim to sliding window : 2 pointer method->look up
                                    // size() fn. counts the no of elements
                                    // if returning a vector do return {1,2,3};
/*int main(){
    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n,target,first,second;
        cin >> n >> target;

        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j] == target){
                    first=i;
                    second=j;
                    break;
                }
                
            }
        }
        cout << '['<< first+1 << ',' << second+1 << ']' << endl;
    }
}*/