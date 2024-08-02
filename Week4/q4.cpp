#include<bits/stdc++.h>
using namespace std;

// *** passing graph by reference passed time limit test, avoids copying

void dfs(vector<vector<int>> &graph,vector<int> &vis,int node,long long &vertices,long long &edges){
    vis[node] = 1;
    edges += graph[node].size();
    vertices++;

    for(auto it : graph[node]){
        if(!vis[it]) dfs(graph,vis,it,vertices,edges);
    }
}

int main(){
    ios::sync_with_stdio(0);        // or ios_base::sync_with_stdio(0)?
    cin.tie(0);                     // also instead of 0, can type false or NULL or nullptr
    cout.tie(0);

    int n,m; cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for(int i=1;i<=m;i++){
        int a,b; cin >> a >> b;
        graph[a].push_back(b);      
        graph[b].push_back(a);
    }
                                            // new functions : 'iota' and 'puts'. Also, can use 'return' in body, since int main also fn.

    vector<int> vis(n+1,0);

    bool reasonable =1;
    for(int i=1;i<=n;i++){                  // combination is O(n) only, dont think 2 loops, together iterate once
        if(!vis[i]){
            //int vertices =0,edges=0;

            long long vertices = 0, edges = 0;  // was getting wrong ans bcoz of overflow, n^2 goes out (or use that nCr trick...)

            dfs(graph,vis,i,vertices,edges);
            edges /= 2;         // double counting
            if(edges != (vertices*(vertices-1))/2) {reasonable = 0; break;  }     // break also improves code
        }
    }
    if(reasonable) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}