#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    long long ans = 0;
    vector<vector<int>> cnt(6, vector<int>(46, 0));  // Initialize cnt array

    for (auto &y : s) {
        int leny = y.length();
        int sumy = 0;
        for (char c : y) {
            sumy += c - '0';
        }
        cnt[leny][sumy]++;
    }

    for (auto &L : s) {
        int lenL = L.length();
        for (int lenr = lenL % 2; lenr <= lenL; lenr += 2) {
            int l = lenL + lenr;
            int suml = 0, sumr = 0;
            for (int i = 0; i < l / 2; i++) {
                suml += L[i] - '0';
            }
            for (int i = l / 2; i < lenL; i++) {
                sumr += L[i] - '0';
            }
            if (suml - sumr >= 0) {
                ans += cnt[lenr][suml - sumr];
            }
        }
    }

    for (auto &R : s) {
        int lenR = R.length();
        for (int lenl = lenR % 2; lenl < lenR; lenl += 2) {
            int l = lenR + lenl;
            int suml = 0, sumr = 0;
            for (int i = l / 2; i < lenR; i++) {
                suml += R[i] - '0';
            }
            for (int i = 0; i < l / 2; i++) {
                sumr += R[i] - '0';
            }
            if (suml - sumr >= 0) {
                ans += cnt[lenl][suml - sumr];
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
