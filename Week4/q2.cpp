#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> list[],int start,vector<bool> &vis){
    vector<int> bfs;        // same name as fn is working ?!
    queue<int> q;
    q.push(start);
    // forgot to mark 1st elem
    vis[start] = 1;

    while(!q.empty()){
        int node = q.front();
        bfs.push_back(q.front());
        q.pop();

        for(auto it : list[node]){
            if(!vis[it]){ vis[it] =1; q.push(it);}
        }

    }
    return bfs;
}

int main(){
    ios::sync_with_stdio(0);        // or ios_base::sync_with_stdio(0)?
    cin.tie(0);                     // also instead of 0, can type false or NULL or nullptr
    cout.tie(0);

    int n,m; cin >> n >> m;
    // 0 based people
    // n nodes(people) and m edges(friends)
    int c[n];
    for(auto &it : c) cin >> it;

    vector<int> adjList[n];
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        adjList[x-1].push_back(y-1);
        adjList[y-1].push_back(x-1);
    }

    vector<bool> vis(n,0);
    long long cost = 0;

    for(int i=0;i<n;i++){
        // vector<int> temp;
        // if(!vis[i]) temp = bfs(adjList,i,vis);
        // cost += *min_element(temp.begin(),temp.end());           wrong : wanna find min cost not min elem

        if(!vis[i]){
            vector<int> temp = bfs(adjList,i,vis);
            int minCost = INT_MAX;
            for(auto it : temp){
                minCost = min(minCost,c[it]);
            }
            cost += minCost;
        }
    }
    cout << cost << '\n';

    return 0;
}