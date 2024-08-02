#include<iostream>
#include<stack>
using namespace std;

bool valid(string s){               // s.length is long long unsigned int so first convert to int
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);

        else if((s[i]==')'&& st.top()=='(')||(s[i]==']'&& st.top()=='[')||
        (s[i]=='}'&& st.top()=='{')) st.pop();
        else return 0;
    }
    return 1;
}

int main(){
    int t; cin >> t;
    for(int i=0;i<t;i++){
        string s; cin >> s;
        cout << boolalpha;
        cout << valid(s) << endl;
        
    }
    return 0;
}