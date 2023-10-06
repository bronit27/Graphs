vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        vector<int>dis(V,0);
        for(int i=0;i<V;i++){
            dis[i]=1e9;
        }
        dis[S]=0;
        while(!pq.empty()){
            int disk=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto x:adj[node]){
                int adjnode=x[0];
                int adjdis=x[1];
                if(disk+adjdis<dis[adjnode]){
                    dis[adjnode]=disk+adjdis;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        return dis;
    }
