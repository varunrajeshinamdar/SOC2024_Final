#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int z=0;z<t;z++){               // cant use a here since compiler confuses with array
        int n,m;
        cin >> n >> m;
        int a[n][m],b[n][m], corresprow[n][m], correspcol[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin >> a[i][j];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin >> b[i][j];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int ii=0;ii<n;ii++){
                    for(int jj=0;jj<m;jj++){
                        if(a[i][j] == b[ii][jj]){       // compiler confused if you use a,b as next variables, so ii and jj used
                            corresprow[i][j] = ii;
                            correspcol[i][j] = jj;
                        }
                    }
                }
            }
        }

        bool row =1, col=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m-1;j++){
                if(corresprow[i][j]-corresprow[i][j+1] != 0) row = 0;
            }
        }

        for(int j=0;j<m;j++){
            for(int i=0;i<n-1;i++){
                if(correspcol[i][j]-correspcol[i+1][j] != 0) col = 0;
            }
        }
        if(row && col) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}