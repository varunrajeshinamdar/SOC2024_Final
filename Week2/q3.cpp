#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<int,int> arr[n];
        for(int it=0;it<n;it++){
            cin >> arr[it].first;
            arr[it].second = it;
        }
    
    sort(arr,arr+n);

    long long int prefixSums[n];
    prefixSums[0] = arr[0].first;
    for(int i=1;i<n;i++){
        //prefixSums[i] += arr[i].first;    see wrong
        prefixSums[i] = prefixSums[i-1] + arr[i].first;
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(count >= i && i>0){
            //nothing need be done
        }else{                
            count=i;
            int j=i;
            while(prefixSums[j] >= arr[j+1].first && j<n-1){
                prefixSums[j] += arr[j+1].first;
                j++; count++;
            }
        }
        arr[i].first = count;       // wont be used again, so reassigning ok
        
    }

    for(int i=0;i<n;i++){
        int temp = arr[i].first;
        arr[i].first = arr[i].second;
        arr[i].second = temp;
    }
    sort(arr,arr+n);                // see tutorial code also **

    for(int i=0;i<n;i++) cout << arr[i].second << ' ';
    cout << '\n';
    }
}



/*#include<bits/stdc++.h>
using namespace std;

int findindex(int n,long long sorted[],int element){
    for(int i=0;i<n;i++){
        if(sorted[i]==element) return i;
    }
    return 0;       // not required, but then gives warning of non valid function
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n; cin >> n;
        int arr[n];
        long long sorted[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
            sorted[i] = arr[i];
        }
        sort(sorted,sorted+n);

        for(int index=0;index<n;index++){
            int count = findindex(n,sorted,arr[index]);
            long long sum=0;                            // big testcase was failing because of sum overflow, so convert sum and sorted arry to long long
            for(int i=0;i<=count;i++) sum+=sorted[i];

            for(int i=count+1;i<n;i++){
                if(sum>=sorted[i]){
                    count++;
                    sum+=sorted[i];
                }
            }
            cout << count << ' ';
        }       
          
    }

    return 0;
}




#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n; cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];

        for(int index=0;index<n;index++){
            int N=n,score = arr[index],count=0;

            for(int i=index;i<N-1;i++) arr[i] = arr[i+1];
            N--;

            for(int b=0;b<n-1;b++){
                for(int i=0;i<N;i++){
                    if(score>=arr[i]){
                        score+=arr[i];
                        for(int j=i;j<N-1;j++) arr[j] = arr[j+1];
                        N--;
                        count++;
                        break;
                    }
                }
            }
            cout << count << ' ' ;
        }    
    }

    return 0;
}*/