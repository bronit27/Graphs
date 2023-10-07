// the edges which if removed will make the graph break into two or more componenets.

int timer=0;
void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],int low[],int tim[],vector<vector<int>>&brig){
    vis[node]=1;
    tim[node]=timer;
    low[node]=timer;
    timer++;
    for(auto x:adj[node]){
        if(x==parent)continue; 
        if(!vis[x]){
            dfs(x,node,vis,adj,low,tim,brig);
            low[node]=min(low[node],low[x]);
            if(tim[node]<low[x]){
                brig.push_back({node,x});
            }
        }else{
            low[node]=min(low[node],low[x]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n);
        int low[n];
        int tim[n];
        vector<vector<int>>brig;
        dfs(0,-1,vis,adj,low,tim,brig);
        return brig;
    }
