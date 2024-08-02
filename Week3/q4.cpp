//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int big = 998'244'353;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];

        vector<long long int> powers(n+1);
        powers[0] = 1;
        for(int i=1;i<n+1;i++){                 // ***imp idea, pre-making array of powers else n^2 if made inside below loop
            powers[i] = powers[i-1]*2 % big;
        }

        for(auto &it : arr) cin >> it;

        long long int sum = 0, minim = 0;

        for(int i=0;i<n;i++){
            sum += arr[i];
            minim = min(minim,sum);
        }
        int posSums = 0;
        long long int count = 0;

        sum = 0;            // again forgot
        if(minim==0){
            
            cout << powers[n] << '\n';
        }else{
            for(int i=0;i<n;i++){
                sum += arr[i];
                if(sum >= 0) posSums++;         // **no need to make vector of min indices etc, also that more complexity while(!vector.empty()) etc
                if(sum == minim){
                    
                    count = (count+ powers[n-1-i+posSums]) %big;       // obv, pow(2,n) doesnt work, too big AND forgot %big
                }                                       // stupid thing doesnt show error for powers[2,....] despite 2 args (was even working for lower cases, how-tf??)


            // **********only above is correct , not count += powers[..] % big, since you'd never end up taking mod of count.

            }
            cout << count << '\n';
        }
    }  
    return 0;
}





// wrong logic, cant simply do *2 for sum>=0, since after modulus more people would come on top

/*
#include<bits/stdc++.h>
using namespace std;
int big = 998'244'353;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(auto &it : arr) cin >> it;

        long long int sum = 0, minim = 0,count = 1;

        for(int i=0;i<n;i++){
            sum += arr[i];
            minim = min(minim,sum);
            if(sum >= 0){
                count *= 2;
                count = count % big;
            }
        }

        int minCount = 0,initCount = count;
        sum = 0;                                  // mistake***: didnt do this, v.frustrating.
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum == minim && sum<0) minCount++;
        }        
        
        if(minCount>=2){
            for(int i=0;i < minCount ; i++){
        count = count*2;
        count %= big;
        }
        count -= initCount;}
    // ***forgot this if loop, didnt matter?? mincount >= 2;    but not working without it

        if(count < 0) cout << big+count << '\n';
        else cout << count << '\n';
    }

    return 0;
}*/