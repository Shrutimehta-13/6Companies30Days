// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if (nums.size() %2 != 0) 
        {
            return false;
        }
        unordered_map<int, int> map;
        for (int i: nums) 
        {
            map[i % k] += 1;
        }
        for (auto const &it: map)
        {
            int r = it.first;
            int f = it.second;
            if (r == 0)
            {
                if (f % 2 != 0) {
                    return false;
                }
            }
            else if (f != map[k - r]) {
                return false;
            }
        }
     
        return true;
     
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
