vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        vector<int>dis(N);
        for(int i=0;i<N;i++){
            dis[i]=1e9;
        }
        q.push(src);
        dis[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                if(dis[node]+1<dis[x]){
                    dis[x]=dis[node]+1;
                    q.push(x);
                }
                
                }
        }
        for(int i=0;i<N;i++){
            if(dis[i]==1e9){
                dis[i]=-1;
            }
        }
        return dis;
    }
