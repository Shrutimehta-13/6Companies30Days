// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph
    
    bool isPath(int start, int dest, vector<int> adj[], vector<int> &isVisited)
    {
        if(start==dest)
        {
            true;
        }
        isVisited[start]=true;
        for(int node:adj[start])
        {
            if(!isVisited[node])
            {
                if(isPath(node, dest, adj, isVisited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> isVisited(V, false);
        vector<int> adj2[V];
        for(int i=0; i<V; i++)
        {
            for(int val:adj[i])
            {
                if((i==c && val==d) || (i==d && val==c))
                {
                    continue;
                }
                adj2[i].push_back(val);
            }
        }
        bool bl = isPath(c,d,adj2,isVisited);
        return !bl;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
