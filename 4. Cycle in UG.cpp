bool dfs(int node,int parent,vector<int> adj[],int vis[]){
        vis[node]=1;
        for(auto x:adj[node]){
            if(!vis[x]){
                if(dfs(x,node,adj,vis))return true;
            }else if(x!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i])if(dfs(i,-1,adj,vis))return true;
        }
        return false;
        
    }

// bfs
bool detect(int node,vector<int> adj[],int vis[]){
        queue<pair<int,int>>q;
        vis[node]=1;
        q.push({node,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto x:adj[node]){
                if(!vis[x]){
                    q.push({x,node});
                    vis[x]=1;
                }else if(x!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i])if(detect(i,adj,vis))return true;
        }
        return false;
        
    }
