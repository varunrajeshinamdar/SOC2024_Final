#include<iostream>
using namespace std;

bool distinct(string s,int l,int k,int start){
    int count[26];
    for(int i=0;i<26;i++) count[i] = 0;

    for(int i=start;i<start+k;i++){
        count[s[i]-'a']++;
    }
    bool yes=1;
    for(int i=start;i<start+k;i++){
        if(count[s[i]-'a']>1) yes=0;
    }
    return yes;
}

int main(){
    int t; cin >> t;            // just like arrays, even in strings you can access elements using indices
    for(int a=0;a<t;a++){       // substrings like subarrays are also contiguous
        
        int k; cin >> k;
        string s; cin >> s;
        int l= s.length(),count=0;

        for(int start=0;start+k<=l;start++){
            if(distinct(s,l,k,start)) count++;
        }
        cout << count << "\n";

    }

    return 0;

}