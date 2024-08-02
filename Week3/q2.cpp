#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string r1,r2;
        cin >> r1 >> r2;
        //vector< vector<char> > grid;              for some reason this doesnt work
        vector<vector<char>> grid(2, vector<char>(n));

        for(int i=0; i<n ;i++){
            grid[0][i] = r1[i];
            grid[1][i] = r2[i];
        }
        bool possible = 1;
        pair<int,int> coord = {0,0};

        for(int i=0;i<n;i++){
            if(grid[0][i] == '<' && i%2==1){
                if(grid[1][i-1] == '<') possible = 0;
                if(i<=n-2 && grid[1][i+1] == '<') possible = 0;
            }
        }
        if(possible) cout << "yes" << "\n";
        else cout << "no" << '\n';
    }

    return 0;
}

/*
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string r1,r2;
        cin >> r1 >> r2;
        //vector< vector<char> > grid;              for some reason this doesnt work
        vector<vector<char>> grid(2, vector<char>(n));

        for(int i=0; i<n ;i++){
            grid[0][i] = r1[i];
            grid[1][i] = r2[i];
        }
        bool possible = 1;
        pair<int,int> coord = {0,0};

        while((coord.first != 1 || coord.second != n-1) && possible==1){        //missed possib cond
            if(grid[coord.first][coord.second+1] == '>') coord.second += 2;
            else if(coord.first == 0){
                coord.first++;
                if(grid[coord.first][coord.second] == '>') coord.second++;
                else if(coord.second >= 1) coord.second--;
                else possible = 0;
            }
            else possible = 0;
        }
    if(possible) cout << "yes" << '\n';
    else cout << "no" << '\n';
    }

    return 0;
}*/