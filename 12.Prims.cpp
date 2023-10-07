// to find the MST of the given tree
// ST: tree with n nodes and n-1 edges such that every node is reachanble from every other node
// MST: ST with the minimum sum of the weight edges.
// This code is only about finding the sum of MST.


int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> vis(V,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            int w=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]==1)continue;
            vis[node]=1;
            sum+=w;
            for(auto x:adj[node]){
                int adjnode=x[0];
                int wd=x[1];
                if(!vis[adjnode]){
                    pq.push({wd,adjnode});
                }
            }
        }
        return sum;
    }
