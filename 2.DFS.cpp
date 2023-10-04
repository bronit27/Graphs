vector<int>ans;
    void dfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        ans.push_back(node);
        for(auto x:adj[node]){
            if(!vis[x]){
                dfs(x,vis,adj);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        dfs(0,vis,adj);
        return ans;
    }
