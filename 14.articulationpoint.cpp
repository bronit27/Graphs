// nodes which will divide the graph in components if removed are called articulation point
int timer=0;

void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],int low[],int tim[],vector<int>&mark){
    vis[node]=1;
    tim[node]=timer;
    low[node]=timer;
    timer++;
     int child=0;
    for(auto x:adj[node]){
        if(x==parent)continue; 
        if(!vis[x]){
            dfs(x,node,vis,adj,low,tim,mark);
            low[node]=min(low[node],low[x]);
            if(tim[node]<=low[x] && parent!=-1){
                mark[node]=1;
            }
            child++;
        }else{
            low[node]=min(low[node],tim[x]);
        }
    }
    if(child>1 && parent==-1){
        mark[node]=1;
    }
}
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int>mark(n,0);
        vector<int>vis(n,0);
        int low[n];
        int tim[n];
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(0,-1,vis,adj,low,tim,mark);
        }
        for(int i=0;i<n;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0)return {-1};
        return ans;
    }
