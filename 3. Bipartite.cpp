// which has even length cycles in it (0 included)
bool isBipartite(vector<vector<int>>& v) {
        int n=v.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
        col[i]=0;
        queue<pair<int,int>>q;
        q.push({i,0});
        while(!q.empty()){
            int node=q.front().first;
            int colr=q.front().second;
            q.pop();
            for(auto x:v[node]){
                if(col[x]==-1){
                    q.push({x,1-colr});
                    col[x]=1-colr;
                }else if(col[x]==colr)return false;
            }
        }
            }
        }
        return true;
    }
