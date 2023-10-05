vector<int>v;
	void dfs(int i,vector<int> adj[] ,vector<int>&vis){
	    vis[i]=1;
	    for(auto x:adj[i]){
	        if(!vis[x]){
	            dfs(x,adj,vis);
	            
	        }
	    }
	    v.push_back(i);
	    return;
	    
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis);
	        }
	    }
	    reverse(v.begin(),v.end());
	    return v;
	    
	}
