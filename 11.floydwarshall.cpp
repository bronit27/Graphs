// to find the shortest path from every possible source to every possibel destination

void shortest_distance(vector<vector<int>>&v){
	    // Code here
	    int n=v.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(v[i][j]==-1)v[i][j]=1e9;
	            if(i==j){
	                v[i][j]=0;
	            }
	        }
	    }
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(v[i][j]==1e9)v[i][j]=-1;
	            
	        }
	    }
	}
