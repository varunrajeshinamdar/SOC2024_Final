#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;     // extra size vector for this question
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);         // taking n+1 to work for both 0 and 1 indexed graphs
        size.resize(n+1,1);                                              // increasing reusability
        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ultParU = findParent(u), ultParV = findParent(v);
        if(ultParU == ultParV) return;
        else if(rank[ultParU] > rank[ultParV]){
            parent[ultParV] = ultParU;
            size[ultParU] += size[ultParV];
        }
        else if(rank[ultParU] < rank[ultParV]){
            parent[ultParU] = ultParV;
            size[ultParV] += size[ultParU];
        }
        else{
            parent[ultParV] = ultParU;
            size[ultParU] += size[ultParV];
            rank[ultParU]++;
        }
    }
    // extra for Q
    int getSize(int k){
        return size[findParent(k)];         // 'size' vector can be accessed only here, so create fn.
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(0);

    int n,m; cin >> n >> m;
    DisjointSet ds(n);
    for(int i=0;i<m;i++){
        int k; cin >> k;
        int arr[k];                          
        for(auto &it : arr) cin >> it;
        // input in Q as 1-indexed

        for(int i=0;i<k-1;i++)  ds.unionByRank(arr[i],arr[i+1]);
    }

    for(int i=1;i <= n;i++) cout << ds.getSize(i) << '\n';
    return 0;
}




/*#include<bits/stdc++.h>
using namespace std;

int bfs(vector<int> graph[],int start,int n){
    queue<int> q;
    q.push(start);
    vector<int> store,vis(n+1,0);
    vis[start] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        store.push_back(node);

        for(auto it : graph[node]){
            if(!vis[it]){vis[it] = 1; q.push(it);}
        }

    }
    return store.size();
}

int main(){
    ios::sync_with_stdio(0);        // or ios_base::sync_with_stdio(0)?
    cin.tie(0);                     // also instead of 0, can type false or NULL or nullptr
    cout.tie(0);

    int n,m; cin >> n >> m;
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        int k; cin >> k;
        int arr[k];                          
        for(auto &it : arr) cin >> it;

        for(int i=0;i<k-1;i++) graph[arr[i]].push_back(arr[i+1]), graph[arr[i+1]].push_back(arr[i]);
    }

    for(int user=1;user<=n;user++){
        cout << bfs(graph,user,n) << '\n';
    }

    return 0;
}*/