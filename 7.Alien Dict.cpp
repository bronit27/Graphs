string findOrder(string dict[], int n, int K) {
        //code here
        vector<int>adj[K];
        vector<int>indeg(K,0);
        for(int i=0;i<n-1;i++){
            string a=dict[i];
            string b=dict[i+1];
            int k=a.size();
            int m=b.size();
            k=min(k,m);
            for(int j=0;j<k;j++){
                if(a[j]!=b[j]){
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    indeg[b[j]-'a']++;
                    break;
                }
            }
        }
        map<int,char>mp;
        for(char i='a';i<='z';i++){
          mp[i-'a']=i;   
        }
        queue<int>q;
        for(int i=0;i<K;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        string ans="";
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // int k=node;
            // string j=to_string(k);
            ans+=mp[node];
            for(auto x:adj[node]){
                indeg[x]--;
                if(indeg[x]==0)q.push(x);
            }
        }
        
        return ans;
        
    }
