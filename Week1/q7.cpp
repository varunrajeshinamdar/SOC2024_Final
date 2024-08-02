#include<bits/stdc++.h>
using namespace std;        // no of bits in n is log(n)

int decToBin(int n){
    int p=0,digits = log2(n)+1;
    for(int i=0;i<digits;i++){
        int k= n%2;
        p += k*pow(10,i);
        n = n/2;
    }
    return p;
}

int count(int n){       // if counting digits before bin, use base 2
    n = decToBin(n);
    int zeroes = 0,digits = log10(n)+1;      // base will be 10, not 2. also, count digits after converting to bin

    for(int i=0;i<digits;i++){      // cant use i<log2(n)+1 bcoz n is changing in the loop
        int temp = n%10;
        if(temp==0) zeroes++;       // since carry over during binary addition interferies with xor
        n /=10;                     // only 0 bits allow possibilities
    }
    return pow(2,zeroes);           // try coding using bitwise operations
}

int main(){
    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n; cin >> n;
        
        cout << count(n) << endl;
    }
}

/*
int main(){
    int t; cin >> t;
    for(int a=0;a<t;a++){
        int n,count =0; cin >> n;
        for(int x=0;x<=n;x++){      // xor also shown as plus with bubble
            if(n+x== (x^n)){        // *** dont forget parantheses
                count++;
            }
        }
        cout << count << endl;
    }
}
*/
