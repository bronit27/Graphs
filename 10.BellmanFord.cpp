/*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
// It is used to find thr shortest path if weights are negative and also checks if there is a negative cyle present.
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto x:edges){
                int a=x[0];
                int b=x[1];
                int d=x[2];
                if(dist[a]!=1e8 && dist[a]+d<dist[b]){
                    dist[b]=dist[a]+d;
                }
            }
        }
        // Nth relaxation to check the negative cycle
        for(auto x:edges){
                int a=x[0];
                int b=x[1];
                int d=x[2];
                if(dist[a]!=1e8 && dist[a]+d<dist[b]){
                    return {-1};
                }
            }
        
        
        return dist;
    }
