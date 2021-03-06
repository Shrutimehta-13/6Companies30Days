// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    
    int countArea(vector<vector<int>>& grid, int x, int y)
    {
        if(x<0 || y<0 || x>grid.size() || y>grid[0].size())
            return 0;
        if(!grid[x][y])
            return 0;
        grid[x][y] = 0;
        return 1 +countArea(grid, x - 1, y) + countArea(grid, x + 1, y) + countArea(grid, x, y - 1)+ countArea(grid, x, y + 1)+ countArea(grid, x-1,y-1)+ countArea(grid, x+1, y + 1)+ countArea(grid, x+1,y-1)+ countArea(grid, x-1,y+1);
    }
    
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        int max_area=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j])
                {
                    max_area = max(countArea(grid, i, j), max_area);
                }
            }
        }
        return max_area;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
