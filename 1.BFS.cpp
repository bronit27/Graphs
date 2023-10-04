vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>temp(V,0);
        temp[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>ans;
        while(!q.empty()){
            int k=q.front();
            q.pop();
            ans.push_back(k);
            for(auto x:adj[k]){
                if(!temp[x]){
                    temp[x]=1;
                    q.push(x);
                }
            }
        }
        return ans;
    }
