#include<bits/stdc++.h>
using namespace std;

struct person{
    int start,end,current;
};

int factorial(int n){
    int fac = 1;
    for(int i=1;i<=n;i++) fac *= i;
    return fac;
}

int combination(int n,int r){           // efficient way to calc combs
    int prod = 1;
    for(int i=1;i<=r;i++){
        //prod *= (n-i+1)/i;            // causes error due to integer truncation
        prod *= n-i+1;
        prod /= i;
    }
    return prod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n; cin >> n;

        person people[n];
        for(int i=0;i<n;i++){
            cin >> people[i].start >> people[i].end;
            people[i].current = people[i].start;
        }
        int maxm = 0;
        for(int i=0;i<n;i++){
            maxm = max(maxm,people[i].end - people[i].start);
        }
        int greetings = 0;

        while(maxm--){
            map<int,int> indexcount;

            for(int i=0;i<n;i++){
                if(people[i].current != people[i].end) people[i].current++;
                indexcount[people[i].current]++;
            }
            for( auto x : indexcount){
                if(x.second > 1) greetings += combination(x.second,2);
            }

        }
        cout << greetings << '\n';
    }
    return 0;
}