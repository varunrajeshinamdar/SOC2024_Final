#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> children[n + 1];
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		children[x].push_back(i);      // parent vector will contain children
	}
	string s;
	cin >> s;

	int result = 0;

	function<int(int)> dp = [&] (int x) {       // not understood this dp properly
        int bal;    

        if(s[x-1] == 'B') bal =-1;
        else bal =1;

		if (children[x].empty()) return bal;
		for (int i : children[x]) {
			bal += dp(i);
		}
		if (bal == 0) {result++;}
		return bal;
	};
	dp(1);
	cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) solve();
}