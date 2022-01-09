// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> v;
        multiset<int, greater<int>> ms;
        for(int i=0; i<k; i++)
        {
            ms.insert(arr[i]);
        }
        v.push_back(*ms.begin());
        for(int i=k; i<n; i++)
        {
            ms.erase(ms.lower_bound(arr[i-k]));
            ms.insert(arr[i]);
            v.push_back(*ms.begin());
        }
        return v;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends
